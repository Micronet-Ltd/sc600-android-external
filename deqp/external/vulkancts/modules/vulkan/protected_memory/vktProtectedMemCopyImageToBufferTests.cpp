/*------------------------------------------------------------------------
 * Vulkan Conformance Tests
 * ------------------------
 *
 * Copyright (c) 2017 The Khronos Group Inc.
 * Copyright (c) 2017 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Protected memory copy image to buffer tests
 *//*--------------------------------------------------------------------*/

#include "vktProtectedMemCopyImageToBufferTests.hpp"

#include "deRandom.hpp"
#include "tcuTestLog.hpp"
#include "tcuVector.hpp"

#include "vkPrograms.hpp"
#include "vktTestCase.hpp"
#include "vktTestGroupUtil.hpp"
#include "vkTypeUtil.hpp"
#include "vkBuilderUtil.hpp"

#include "vktProtectedMemContext.hpp"
#include "vktProtectedMemUtils.hpp"
#include "vktProtectedMemBufferValidator.hpp"

namespace vkt
{
namespace ProtectedMem
{

namespace
{

enum {
	BUFFER_SIZE		= 256,
	RENDER_WIDTH	= 8,
	RENDER_HEIGHT	= 8,

	MAX_POSITION	= BUFFER_SIZE / 4,
};

template<typename T>
class CopyImageToBufferTestInstance : public ProtectedTestInstance
{
public:
									CopyImageToBufferTestInstance	(Context&						ctx,
																	 const vk::VkClearColorValue	fillValue,
																	 const BufferValidator<T>&		validator,
																	 const CmdBufferType			cmdBufferType);
	virtual tcu::TestStatus			iterate							(void);

private:
	const vk::VkFormat				m_imageFormat;
	const vk::VkClearColorValue		m_fillValue;
	const BufferValidator<T>&		m_validator;
	const CmdBufferType					m_cmdBufferType;
};


template<typename T>
class CopyImageToBufferTestCase : public TestCase
{
public:
							CopyImageToBufferTestCase	(tcu::TestContext&		testCtx,
														 const std::string&		name,
														 vk::VkClearColorValue	fillValue,
														 ValidationData<T>		data,
														 CmdBufferType			cmdBufferType)
								: TestCase				(testCtx, name, "Copy image to buffer.")
								, m_fillValue			(fillValue)
								, m_validator			(data)
								, m_cmdBufferType		(cmdBufferType)
							{
							}

	virtual					~CopyImageToBufferTestCase	(void) {}
	virtual TestInstance*	createInstance				(Context& ctx) const
							{
								return new CopyImageToBufferTestInstance<T>(ctx, m_fillValue, m_validator, m_cmdBufferType);
							}
	virtual void			initPrograms				(vk::SourceCollections&	programCollection) const
							{
								m_validator.initPrograms(programCollection);
							}
private:
	vk::VkClearColorValue	m_fillValue;
	BufferValidator<T>		m_validator;
	CmdBufferType			m_cmdBufferType;
};

template<typename T>
CopyImageToBufferTestInstance<T>::CopyImageToBufferTestInstance	(Context&						ctx,
																 const vk::VkClearColorValue	fillValue,
																 const BufferValidator<T>&		validator,
																 const CmdBufferType			cmdBufferType)
	: ProtectedTestInstance	(ctx)
	, m_imageFormat			(vk::VK_FORMAT_R32G32B32A32_UINT)
	, m_fillValue			(fillValue)
	, m_validator			(validator)
	, m_cmdBufferType		(cmdBufferType)
{
}

template<typename T>
tcu::TestStatus CopyImageToBufferTestInstance<T>::iterate()
{
	ProtectedContext&					ctx					(m_protectedContext);
	const vk::DeviceInterface&			vk					= ctx.getDeviceInterface();
	const vk::VkDevice					device				= ctx.getDevice();
	const vk::VkQueue					queue				= ctx.getQueue();
	const deUint32						queueFamilyIndex	= ctx.getQueueFamilyIndex();

	// Create image
	de::MovePtr<vk::ImageWithMemory>	colorImage			= createImage2D(ctx, PROTECTION_ENABLED, queueFamilyIndex,
																			RENDER_WIDTH, RENDER_HEIGHT,
																			m_imageFormat,
																			vk::VK_IMAGE_USAGE_TRANSFER_DST_BIT
																			| vk::VK_IMAGE_USAGE_TRANSFER_SRC_BIT
																			| vk::VK_IMAGE_USAGE_TRANSFER_DST_BIT);
	de::MovePtr<vk::BufferWithMemory>	dstBuffer			(makeBuffer(ctx,
																		PROTECTION_ENABLED,
																		queueFamilyIndex,
																		(deUint32)(BUFFER_SIZE * sizeof(deUint32)),
																		vk::VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT
																			| vk::VK_BUFFER_USAGE_TRANSFER_DST_BIT,
																		vk::MemoryRequirement::Protected));

	vk::Unique<vk::VkCommandPool>		cmdPool				(makeCommandPool(vk, device, PROTECTION_ENABLED, queueFamilyIndex));
	vk::Unique<vk::VkCommandBuffer>		cmdBuffer			(vk::allocateCommandBuffer(vk, device, *cmdPool, vk::VK_COMMAND_BUFFER_LEVEL_PRIMARY));
	vk::Unique<vk::VkCommandBuffer>		secondaryCmdBuffer	(vk::allocateCommandBuffer(vk, device, *cmdPool, vk::VK_COMMAND_BUFFER_LEVEL_SECONDARY));
	vk::VkCommandBuffer					targetCmdBuffer		= (m_cmdBufferType == CMD_BUFFER_SECONDARY) ? *secondaryCmdBuffer : *cmdBuffer;

	// Begin cmd buffer
	beginCommandBuffer(vk, *cmdBuffer);

	if (m_cmdBufferType == CMD_BUFFER_SECONDARY)
	{
		// Begin secondary command buffer
		const vk::VkCommandBufferInheritanceInfo	secCmdBufInheritInfo	=
		{
			vk::VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO,
			DE_NULL,
			(vk::VkRenderPass)0u,										// renderPass
			0u,															// subpass
			(vk::VkFramebuffer)0u,										// framebuffer
			VK_FALSE,													// occlusionQueryEnable
			(vk::VkQueryControlFlags)0u,								// queryFlags
			(vk::VkQueryPipelineStatisticFlags)0u,						// pipelineStatistics
		};
		beginSecondaryCommandBuffer(vk, *secondaryCmdBuffer, secCmdBufInheritInfo);
	}

	// Start image barrier for source image.
	{
		const vk::VkImageMemoryBarrier	startImgBarrier		=
		{
			vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,			// VkStructureType		sType
			DE_NULL,											// const void*			pNext
			0,													// VkAccessFlags		srcAccessMask
			vk::VK_ACCESS_TRANSFER_WRITE_BIT,					// VkAccessFlags		dstAccessMask
			vk::VK_IMAGE_LAYOUT_UNDEFINED,						// VkImageLayout		oldLayout
			vk::VK_IMAGE_LAYOUT_GENERAL,						// VkImageLayout		newLayout
			queueFamilyIndex,									// uint32_t				srcQueueFamilyIndex
			queueFamilyIndex,									// uint32_t				dstQueueFamilyIndex
			**colorImage,										// VkImage				image
			{
				vk::VK_IMAGE_ASPECT_COLOR_BIT,					// VkImageAspectFlags	aspectMask
				0u,												// uint32_t				baseMipLevel
				1u,												// uint32_t				mipLevels
				0u,												// uint32_t				baseArraySlice
				1u,												// uint32_t				subresourceRange
			}
		};

		vk.cmdPipelineBarrier(targetCmdBuffer,
							  vk::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
							  vk::VK_PIPELINE_STAGE_TRANSFER_BIT,
							  (vk::VkDependencyFlags)0,
							  0, (const vk::VkMemoryBarrier*)DE_NULL,
							  0, (const vk::VkBufferMemoryBarrier*)DE_NULL,
							  1, &startImgBarrier);
	}

	// Image clear
	const vk::VkImageSubresourceRange subresourceRange =
	{
		vk::VK_IMAGE_ASPECT_COLOR_BIT,	// VkImageAspectFlags	aspectMask
		0u,								// uint32_t				baseMipLevel
		1u,								// uint32_t				levelCount
		0u,								// uint32_t				baseArrayLayer
		1u,								// uint32_t				layerCount
	};

	vk.cmdClearColorImage(targetCmdBuffer, **colorImage, vk::VK_IMAGE_LAYOUT_GENERAL, &m_fillValue, 1, &subresourceRange);

	// Image barrier to change accessMask to transfer read bit for source image.
	{
		const vk::VkImageMemoryBarrier initializeBarrier =
		{
			vk::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER,			// VkStructureType		sType
			DE_NULL,											// const void*			pNext
			vk::VK_ACCESS_TRANSFER_WRITE_BIT,					// VkAccessFlags		srcAccessMask
			vk::VK_ACCESS_TRANSFER_READ_BIT,					// VkAccessFlags		dstAccessMask
			vk::VK_IMAGE_LAYOUT_GENERAL,						// VkImageLayout		oldLayout
			vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,			// VkImageLayout		newLayout
			queueFamilyIndex,									// uint32_t				srcQueueFamilyIndex
			queueFamilyIndex,									// uint32_t				dstQueueFamilyIndex
			**colorImage,										// VkImage				image
			{
				vk::VK_IMAGE_ASPECT_COLOR_BIT,					// VkImageAspectFlags	aspectMask
				0u,												// uint32_t				baseMipLevel
				1u,												// uint32_t				mipLevels
				0u,												// uint32_t				baseArraySlice
				1u,												// uint32_t				subresourceRange
			}
		};

		vk.cmdPipelineBarrier(targetCmdBuffer,
							  vk::VK_PIPELINE_STAGE_TRANSFER_BIT,
							  vk::VK_PIPELINE_STAGE_TRANSFER_BIT,
							  (vk::VkDependencyFlags)0,
							  0, (const vk::VkMemoryBarrier*)DE_NULL,
							  0, (const vk::VkBufferMemoryBarrier*)DE_NULL,
							  1, &initializeBarrier);
	}

	// Copy image to buffer
	const vk::VkImageSubresourceLayers	subresourceLayers	=
	{
		vk::VK_IMAGE_ASPECT_COLOR_BIT,	// VkImageAspectFlags	aspectMask
		0u,								// uint32_t				mipLevel
		0u,								// uint32_t				baseArrayLayer
		1u,								// uint32_t				layerCount
	};
	const vk::VkOffset3D				nullOffset			= {0u, 0u, 0u};
	const vk::VkExtent3D				imageExtent			= {(deUint32)RENDER_WIDTH, (deUint32)RENDER_HEIGHT, 1u};
	const vk::VkBufferImageCopy			copyRegion			=
	{
		0ull,							// VkDeviceSize				srcOffset;
		0,								// uint32_t					bufferRowLength
		0,								// uint32_t					bufferImageHeight
		subresourceLayers,				// VkImageSubresourceLayers	imageSubresource
		nullOffset,						// VkOffset3D				imageOffset
		imageExtent,					// VkExtent3D				imageExtent
	};
	vk.cmdCopyImageToBuffer(targetCmdBuffer, **colorImage, vk::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, **dstBuffer, 1u, &copyRegion);

	{
		// Buffer validator reads buffer in compute shader
		const vk::VkBufferMemoryBarrier	endBufferBarrier		=
		{
			vk::VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER,		// VkStructureType		sType
			DE_NULL,											// const void*			pNext
			vk::VK_ACCESS_TRANSFER_WRITE_BIT,					// VkAccessFlags		srcAccessMask
			vk::VK_ACCESS_SHADER_READ_BIT,						// VkAccessFlags		dstAccessMask
			queueFamilyIndex,									// uint32_t				srcQueueFamilyIndex
			queueFamilyIndex,									// uint32_t				dstQueueFamilyIndex
			**dstBuffer,										// VkBuffer				buffer
			0u,													// VkDeviceSize			offset
			VK_WHOLE_SIZE,										// VkDeviceSize			size
		};
		vk.cmdPipelineBarrier(targetCmdBuffer,
								vk::VK_PIPELINE_STAGE_TRANSFER_BIT,
								vk::VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
								(vk::VkDependencyFlags)0,
								0, (const vk::VkMemoryBarrier*)DE_NULL,
								1, &endBufferBarrier,
								0, (const vk::VkImageMemoryBarrier*)DE_NULL);
	}

	if (m_cmdBufferType == CMD_BUFFER_SECONDARY)
	{
		VK_CHECK(vk.endCommandBuffer(*secondaryCmdBuffer));
		vk.cmdExecuteCommands(*cmdBuffer, 1u, &secondaryCmdBuffer.get());
	}

	VK_CHECK(vk.endCommandBuffer(*cmdBuffer));

	// Submit command buffer
	const vk::Unique<vk::VkFence>	fence		(vk::createFence(vk, device));
	VK_CHECK(queueSubmit(ctx, PROTECTION_ENABLED, queue, *cmdBuffer, *fence, ~0ull));

	// Log out test data
	ctx.getTestContext().getLog()
		<< tcu::TestLog::Message << "Fill value: " << m_fillValue << tcu::TestLog::EndMessage;

	// Validate resulting buffer
	if (m_validator.validateBuffer(ctx, **dstBuffer))
		return tcu::TestStatus::pass("Everything went OK");
	else
		return tcu::TestStatus::fail("Something went really wrong");
}

tcu::TestCaseGroup*	createCopyImageToFloatBufferTests(tcu::TestContext& testCtx, CmdBufferType cmdBufferType)
{
	struct {
		const vk::VkClearColorValue		fillValue;
		const ValidationDataVec4		data;
	} testData[] = {
		{	{ { 0.0f, 0.0f, 0.0f, 0.0f } },
			{
				{ tcu::IVec4(0),	tcu::IVec4(1),		tcu::IVec4(3),		tcu::IVec4(7)		},
				{ tcu::Vec4(0.0f),	tcu::Vec4(0.0f),	tcu::Vec4(0.0f),	tcu::Vec4(0.0f)		}
			}
		},
		{	{ { 1.0f, 1.0f, 1.0f, 1.0f } },
			{
				{ tcu::IVec4(2),	tcu::IVec4(4),		tcu::IVec4(16),		tcu::IVec4(15)		},
				{ tcu::Vec4(1.0f),	tcu::Vec4(1.0f),	tcu::Vec4(1.0f),	tcu::Vec4(1.0f)		}
			}
		},
		{	{ { 0.24f, 0.24f, 0.24f, 0.24f } },
			{
				{ tcu::IVec4(3),	tcu::IVec4(7),		tcu::IVec4(17),		tcu::IVec4(37)		},
				{ tcu::Vec4(0.24f),	tcu::Vec4(0.24f),	tcu::Vec4(0.24f),	tcu::Vec4(0.24f)	}
			}
		},
		{	{ { 0.68f, 0.68f, 0.68f, 0.68f } },
			{
				{ tcu::IVec4(7),	tcu::IVec4(11),		tcu::IVec4(21),		tcu::IVec4(40)		},
				{ tcu::Vec4(0.68f),	tcu::Vec4(0.68f),	tcu::Vec4(0.68f),	tcu::Vec4(0.68f)	}
			}
		},
		{	{ { 0.92f, 0.92f, 0.92f, 0.92f } },
			{
				{ tcu::IVec4(5),	tcu::IVec4(21),		tcu::IVec4(40),		tcu::IVec4(57)		},
				{ tcu::Vec4(0.92f),	tcu::Vec4(0.92f),	tcu::Vec4(0.92f),	tcu::Vec4(0.92f)	}
			}
		},
		{	{ { 0.49f, 0.49f, 0.49f, 0.49f } },
			{
				{ tcu::IVec4(23),	tcu::IVec4(37),		tcu::IVec4(51),		tcu::IVec4(63)		},
				{ tcu::Vec4(0.49f),	tcu::Vec4(0.49f),	tcu::Vec4(0.49f),	tcu::Vec4(0.49f)	}
			}
		},
	};

	de::MovePtr<tcu::TestCaseGroup>	copyStaticTests		(new tcu::TestCaseGroup(testCtx, "static", "Copy Image to Buffer Tests with static input"));

	for (int ndx = 0; ndx < DE_LENGTH_OF_ARRAY(testData); ++ndx)
	{
		DE_ASSERT(testData[ndx].data.positions[0].x() < MAX_POSITION);
		DE_ASSERT(testData[ndx].data.positions[1].x() < MAX_POSITION);
		DE_ASSERT(testData[ndx].data.positions[2].x() < MAX_POSITION);
		DE_ASSERT(testData[ndx].data.positions[3].x() < MAX_POSITION);

		const std::string name = "copy_" + de::toString(ndx + 1);
		copyStaticTests->addChild(new CopyImageToBufferTestCase<tcu::Vec4>(testCtx, name.c_str(), testData[ndx].fillValue, testData[ndx].data, cmdBufferType));
	}

	/* Add a few randomized tests */
	de::MovePtr<tcu::TestCaseGroup>	copyRandomTests		(new tcu::TestCaseGroup(testCtx, "random", "Copy Image to Buffer Tests with random input"));
	const int						testCount			= 10;
	de::Random						rnd					(testCtx.getCommandLine().getBaseSeed());
	for (int ndx = 0; ndx < testCount; ++ndx)
	{
		const std::string	name		= "copy_" + de::toString(ndx + 1);
		vk::VkClearValue	clearValue	= vk::makeClearValueColorF32(
											rnd.getFloat(0.0, 1.0f),
											rnd.getFloat(0.0, 1.0f),
											rnd.getFloat(0.0, 1.0f),
											rnd.getFloat(0.0, 1.0f));

		tcu::Vec4			refValue	(clearValue.color.float32[0], clearValue.color.float32[1], clearValue.color.float32[2], clearValue.color.float32[3]);
		ValidationDataVec4	data		=
		{
			{ tcu::IVec4(rnd.getInt(0, MAX_POSITION - 1)),
			  tcu::IVec4(rnd.getInt(0, MAX_POSITION - 1)),
			  tcu::IVec4(rnd.getInt(0, MAX_POSITION - 1)),
			  tcu::IVec4(rnd.getInt(0, MAX_POSITION - 1)) },
			{ refValue, refValue, refValue, refValue }
		};

		DE_ASSERT(data.positions[0].x() < MAX_POSITION);
		DE_ASSERT(data.positions[1].x() < MAX_POSITION);
		DE_ASSERT(data.positions[2].x() < MAX_POSITION);
		DE_ASSERT(data.positions[3].x() < MAX_POSITION);

		copyRandomTests->addChild(new CopyImageToBufferTestCase<tcu::Vec4>(testCtx, name.c_str(), clearValue.color, data, cmdBufferType));
	}

	std::string groupName = getCmdBufferTypeStr(cmdBufferType);
	std::string groupDesc = "Copy Image to Buffer Tests with " + groupName + " command buffer";
	de::MovePtr<tcu::TestCaseGroup> copyTests (new tcu::TestCaseGroup(testCtx, groupName.c_str(), groupDesc.c_str()));
	copyTests->addChild(copyStaticTests.release());
	copyTests->addChild(copyRandomTests.release());
	return copyTests.release();
}

} // anonymous

tcu::TestCaseGroup*	createCopyImageToFloatBufferTests (tcu::TestContext& testCtx)
{
	de::MovePtr<tcu::TestCaseGroup> copyTests (new tcu::TestCaseGroup(testCtx, "copy_image_to_float_buffer", "Copy Image to Buffer Tests"));

	copyTests->addChild(createCopyImageToFloatBufferTests(testCtx, CMD_BUFFER_PRIMARY));
	copyTests->addChild(createCopyImageToFloatBufferTests(testCtx, CMD_BUFFER_SECONDARY));

	return copyTests.release();
}

} // ProtectedMem
} // vkt
