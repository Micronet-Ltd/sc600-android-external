/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */
m_vk.destroyDevice								= (DestroyDeviceFunc)								GET_PROC_ADDR("vkDestroyDevice");
m_vk.getDeviceQueue								= (GetDeviceQueueFunc)								GET_PROC_ADDR("vkGetDeviceQueue");
m_vk.queueSubmit								= (QueueSubmitFunc)									GET_PROC_ADDR("vkQueueSubmit");
m_vk.queueWaitIdle								= (QueueWaitIdleFunc)								GET_PROC_ADDR("vkQueueWaitIdle");
m_vk.deviceWaitIdle								= (DeviceWaitIdleFunc)								GET_PROC_ADDR("vkDeviceWaitIdle");
m_vk.allocateMemory								= (AllocateMemoryFunc)								GET_PROC_ADDR("vkAllocateMemory");
m_vk.freeMemory									= (FreeMemoryFunc)									GET_PROC_ADDR("vkFreeMemory");
m_vk.mapMemory									= (MapMemoryFunc)									GET_PROC_ADDR("vkMapMemory");
m_vk.unmapMemory								= (UnmapMemoryFunc)									GET_PROC_ADDR("vkUnmapMemory");
m_vk.flushMappedMemoryRanges					= (FlushMappedMemoryRangesFunc)						GET_PROC_ADDR("vkFlushMappedMemoryRanges");
m_vk.invalidateMappedMemoryRanges				= (InvalidateMappedMemoryRangesFunc)				GET_PROC_ADDR("vkInvalidateMappedMemoryRanges");
m_vk.getDeviceMemoryCommitment					= (GetDeviceMemoryCommitmentFunc)					GET_PROC_ADDR("vkGetDeviceMemoryCommitment");
m_vk.bindBufferMemory							= (BindBufferMemoryFunc)							GET_PROC_ADDR("vkBindBufferMemory");
m_vk.bindImageMemory							= (BindImageMemoryFunc)								GET_PROC_ADDR("vkBindImageMemory");
m_vk.getBufferMemoryRequirements				= (GetBufferMemoryRequirementsFunc)					GET_PROC_ADDR("vkGetBufferMemoryRequirements");
m_vk.getImageMemoryRequirements					= (GetImageMemoryRequirementsFunc)					GET_PROC_ADDR("vkGetImageMemoryRequirements");
m_vk.getImageSparseMemoryRequirements			= (GetImageSparseMemoryRequirementsFunc)			GET_PROC_ADDR("vkGetImageSparseMemoryRequirements");
m_vk.queueBindSparse							= (QueueBindSparseFunc)								GET_PROC_ADDR("vkQueueBindSparse");
m_vk.createFence								= (CreateFenceFunc)									GET_PROC_ADDR("vkCreateFence");
m_vk.destroyFence								= (DestroyFenceFunc)								GET_PROC_ADDR("vkDestroyFence");
m_vk.resetFences								= (ResetFencesFunc)									GET_PROC_ADDR("vkResetFences");
m_vk.getFenceStatus								= (GetFenceStatusFunc)								GET_PROC_ADDR("vkGetFenceStatus");
m_vk.waitForFences								= (WaitForFencesFunc)								GET_PROC_ADDR("vkWaitForFences");
m_vk.createSemaphore							= (CreateSemaphoreFunc)								GET_PROC_ADDR("vkCreateSemaphore");
m_vk.destroySemaphore							= (DestroySemaphoreFunc)							GET_PROC_ADDR("vkDestroySemaphore");
m_vk.createEvent								= (CreateEventFunc)									GET_PROC_ADDR("vkCreateEvent");
m_vk.destroyEvent								= (DestroyEventFunc)								GET_PROC_ADDR("vkDestroyEvent");
m_vk.getEventStatus								= (GetEventStatusFunc)								GET_PROC_ADDR("vkGetEventStatus");
m_vk.setEvent									= (SetEventFunc)									GET_PROC_ADDR("vkSetEvent");
m_vk.resetEvent									= (ResetEventFunc)									GET_PROC_ADDR("vkResetEvent");
m_vk.createQueryPool							= (CreateQueryPoolFunc)								GET_PROC_ADDR("vkCreateQueryPool");
m_vk.destroyQueryPool							= (DestroyQueryPoolFunc)							GET_PROC_ADDR("vkDestroyQueryPool");
m_vk.getQueryPoolResults						= (GetQueryPoolResultsFunc)							GET_PROC_ADDR("vkGetQueryPoolResults");
m_vk.createBuffer								= (CreateBufferFunc)								GET_PROC_ADDR("vkCreateBuffer");
m_vk.destroyBuffer								= (DestroyBufferFunc)								GET_PROC_ADDR("vkDestroyBuffer");
m_vk.createBufferView							= (CreateBufferViewFunc)							GET_PROC_ADDR("vkCreateBufferView");
m_vk.destroyBufferView							= (DestroyBufferViewFunc)							GET_PROC_ADDR("vkDestroyBufferView");
m_vk.createImage								= (CreateImageFunc)									GET_PROC_ADDR("vkCreateImage");
m_vk.destroyImage								= (DestroyImageFunc)								GET_PROC_ADDR("vkDestroyImage");
m_vk.getImageSubresourceLayout					= (GetImageSubresourceLayoutFunc)					GET_PROC_ADDR("vkGetImageSubresourceLayout");
m_vk.createImageView							= (CreateImageViewFunc)								GET_PROC_ADDR("vkCreateImageView");
m_vk.destroyImageView							= (DestroyImageViewFunc)							GET_PROC_ADDR("vkDestroyImageView");
m_vk.createShaderModule							= (CreateShaderModuleFunc)							GET_PROC_ADDR("vkCreateShaderModule");
m_vk.destroyShaderModule						= (DestroyShaderModuleFunc)							GET_PROC_ADDR("vkDestroyShaderModule");
m_vk.createPipelineCache						= (CreatePipelineCacheFunc)							GET_PROC_ADDR("vkCreatePipelineCache");
m_vk.destroyPipelineCache						= (DestroyPipelineCacheFunc)						GET_PROC_ADDR("vkDestroyPipelineCache");
m_vk.getPipelineCacheData						= (GetPipelineCacheDataFunc)						GET_PROC_ADDR("vkGetPipelineCacheData");
m_vk.mergePipelineCaches						= (MergePipelineCachesFunc)							GET_PROC_ADDR("vkMergePipelineCaches");
m_vk.createGraphicsPipelines					= (CreateGraphicsPipelinesFunc)						GET_PROC_ADDR("vkCreateGraphicsPipelines");
m_vk.createComputePipelines						= (CreateComputePipelinesFunc)						GET_PROC_ADDR("vkCreateComputePipelines");
m_vk.destroyPipeline							= (DestroyPipelineFunc)								GET_PROC_ADDR("vkDestroyPipeline");
m_vk.createPipelineLayout						= (CreatePipelineLayoutFunc)						GET_PROC_ADDR("vkCreatePipelineLayout");
m_vk.destroyPipelineLayout						= (DestroyPipelineLayoutFunc)						GET_PROC_ADDR("vkDestroyPipelineLayout");
m_vk.createSampler								= (CreateSamplerFunc)								GET_PROC_ADDR("vkCreateSampler");
m_vk.destroySampler								= (DestroySamplerFunc)								GET_PROC_ADDR("vkDestroySampler");
m_vk.createDescriptorSetLayout					= (CreateDescriptorSetLayoutFunc)					GET_PROC_ADDR("vkCreateDescriptorSetLayout");
m_vk.destroyDescriptorSetLayout					= (DestroyDescriptorSetLayoutFunc)					GET_PROC_ADDR("vkDestroyDescriptorSetLayout");
m_vk.createDescriptorPool						= (CreateDescriptorPoolFunc)						GET_PROC_ADDR("vkCreateDescriptorPool");
m_vk.destroyDescriptorPool						= (DestroyDescriptorPoolFunc)						GET_PROC_ADDR("vkDestroyDescriptorPool");
m_vk.resetDescriptorPool						= (ResetDescriptorPoolFunc)							GET_PROC_ADDR("vkResetDescriptorPool");
m_vk.allocateDescriptorSets						= (AllocateDescriptorSetsFunc)						GET_PROC_ADDR("vkAllocateDescriptorSets");
m_vk.freeDescriptorSets							= (FreeDescriptorSetsFunc)							GET_PROC_ADDR("vkFreeDescriptorSets");
m_vk.updateDescriptorSets						= (UpdateDescriptorSetsFunc)						GET_PROC_ADDR("vkUpdateDescriptorSets");
m_vk.createFramebuffer							= (CreateFramebufferFunc)							GET_PROC_ADDR("vkCreateFramebuffer");
m_vk.destroyFramebuffer							= (DestroyFramebufferFunc)							GET_PROC_ADDR("vkDestroyFramebuffer");
m_vk.createRenderPass							= (CreateRenderPassFunc)							GET_PROC_ADDR("vkCreateRenderPass");
m_vk.destroyRenderPass							= (DestroyRenderPassFunc)							GET_PROC_ADDR("vkDestroyRenderPass");
m_vk.getRenderAreaGranularity					= (GetRenderAreaGranularityFunc)					GET_PROC_ADDR("vkGetRenderAreaGranularity");
m_vk.createCommandPool							= (CreateCommandPoolFunc)							GET_PROC_ADDR("vkCreateCommandPool");
m_vk.destroyCommandPool							= (DestroyCommandPoolFunc)							GET_PROC_ADDR("vkDestroyCommandPool");
m_vk.resetCommandPool							= (ResetCommandPoolFunc)							GET_PROC_ADDR("vkResetCommandPool");
m_vk.allocateCommandBuffers						= (AllocateCommandBuffersFunc)						GET_PROC_ADDR("vkAllocateCommandBuffers");
m_vk.freeCommandBuffers							= (FreeCommandBuffersFunc)							GET_PROC_ADDR("vkFreeCommandBuffers");
m_vk.beginCommandBuffer							= (BeginCommandBufferFunc)							GET_PROC_ADDR("vkBeginCommandBuffer");
m_vk.endCommandBuffer							= (EndCommandBufferFunc)							GET_PROC_ADDR("vkEndCommandBuffer");
m_vk.resetCommandBuffer							= (ResetCommandBufferFunc)							GET_PROC_ADDR("vkResetCommandBuffer");
m_vk.cmdBindPipeline							= (CmdBindPipelineFunc)								GET_PROC_ADDR("vkCmdBindPipeline");
m_vk.cmdSetViewport								= (CmdSetViewportFunc)								GET_PROC_ADDR("vkCmdSetViewport");
m_vk.cmdSetScissor								= (CmdSetScissorFunc)								GET_PROC_ADDR("vkCmdSetScissor");
m_vk.cmdSetLineWidth							= (CmdSetLineWidthFunc)								GET_PROC_ADDR("vkCmdSetLineWidth");
m_vk.cmdSetDepthBias							= (CmdSetDepthBiasFunc)								GET_PROC_ADDR("vkCmdSetDepthBias");
m_vk.cmdSetBlendConstants						= (CmdSetBlendConstantsFunc)						GET_PROC_ADDR("vkCmdSetBlendConstants");
m_vk.cmdSetDepthBounds							= (CmdSetDepthBoundsFunc)							GET_PROC_ADDR("vkCmdSetDepthBounds");
m_vk.cmdSetStencilCompareMask					= (CmdSetStencilCompareMaskFunc)					GET_PROC_ADDR("vkCmdSetStencilCompareMask");
m_vk.cmdSetStencilWriteMask						= (CmdSetStencilWriteMaskFunc)						GET_PROC_ADDR("vkCmdSetStencilWriteMask");
m_vk.cmdSetStencilReference						= (CmdSetStencilReferenceFunc)						GET_PROC_ADDR("vkCmdSetStencilReference");
m_vk.cmdBindDescriptorSets						= (CmdBindDescriptorSetsFunc)						GET_PROC_ADDR("vkCmdBindDescriptorSets");
m_vk.cmdBindIndexBuffer							= (CmdBindIndexBufferFunc)							GET_PROC_ADDR("vkCmdBindIndexBuffer");
m_vk.cmdBindVertexBuffers						= (CmdBindVertexBuffersFunc)						GET_PROC_ADDR("vkCmdBindVertexBuffers");
m_vk.cmdDraw									= (CmdDrawFunc)										GET_PROC_ADDR("vkCmdDraw");
m_vk.cmdDrawIndexed								= (CmdDrawIndexedFunc)								GET_PROC_ADDR("vkCmdDrawIndexed");
m_vk.cmdDrawIndirect							= (CmdDrawIndirectFunc)								GET_PROC_ADDR("vkCmdDrawIndirect");
m_vk.cmdDrawIndexedIndirect						= (CmdDrawIndexedIndirectFunc)						GET_PROC_ADDR("vkCmdDrawIndexedIndirect");
m_vk.cmdDispatch								= (CmdDispatchFunc)									GET_PROC_ADDR("vkCmdDispatch");
m_vk.cmdDispatchIndirect						= (CmdDispatchIndirectFunc)							GET_PROC_ADDR("vkCmdDispatchIndirect");
m_vk.cmdCopyBuffer								= (CmdCopyBufferFunc)								GET_PROC_ADDR("vkCmdCopyBuffer");
m_vk.cmdCopyImage								= (CmdCopyImageFunc)								GET_PROC_ADDR("vkCmdCopyImage");
m_vk.cmdBlitImage								= (CmdBlitImageFunc)								GET_PROC_ADDR("vkCmdBlitImage");
m_vk.cmdCopyBufferToImage						= (CmdCopyBufferToImageFunc)						GET_PROC_ADDR("vkCmdCopyBufferToImage");
m_vk.cmdCopyImageToBuffer						= (CmdCopyImageToBufferFunc)						GET_PROC_ADDR("vkCmdCopyImageToBuffer");
m_vk.cmdUpdateBuffer							= (CmdUpdateBufferFunc)								GET_PROC_ADDR("vkCmdUpdateBuffer");
m_vk.cmdFillBuffer								= (CmdFillBufferFunc)								GET_PROC_ADDR("vkCmdFillBuffer");
m_vk.cmdClearColorImage							= (CmdClearColorImageFunc)							GET_PROC_ADDR("vkCmdClearColorImage");
m_vk.cmdClearDepthStencilImage					= (CmdClearDepthStencilImageFunc)					GET_PROC_ADDR("vkCmdClearDepthStencilImage");
m_vk.cmdClearAttachments						= (CmdClearAttachmentsFunc)							GET_PROC_ADDR("vkCmdClearAttachments");
m_vk.cmdResolveImage							= (CmdResolveImageFunc)								GET_PROC_ADDR("vkCmdResolveImage");
m_vk.cmdSetEvent								= (CmdSetEventFunc)									GET_PROC_ADDR("vkCmdSetEvent");
m_vk.cmdResetEvent								= (CmdResetEventFunc)								GET_PROC_ADDR("vkCmdResetEvent");
m_vk.cmdWaitEvents								= (CmdWaitEventsFunc)								GET_PROC_ADDR("vkCmdWaitEvents");
m_vk.cmdPipelineBarrier							= (CmdPipelineBarrierFunc)							GET_PROC_ADDR("vkCmdPipelineBarrier");
m_vk.cmdBeginQuery								= (CmdBeginQueryFunc)								GET_PROC_ADDR("vkCmdBeginQuery");
m_vk.cmdEndQuery								= (CmdEndQueryFunc)									GET_PROC_ADDR("vkCmdEndQuery");
m_vk.cmdResetQueryPool							= (CmdResetQueryPoolFunc)							GET_PROC_ADDR("vkCmdResetQueryPool");
m_vk.cmdWriteTimestamp							= (CmdWriteTimestampFunc)							GET_PROC_ADDR("vkCmdWriteTimestamp");
m_vk.cmdCopyQueryPoolResults					= (CmdCopyQueryPoolResultsFunc)						GET_PROC_ADDR("vkCmdCopyQueryPoolResults");
m_vk.cmdPushConstants							= (CmdPushConstantsFunc)							GET_PROC_ADDR("vkCmdPushConstants");
m_vk.cmdBeginRenderPass							= (CmdBeginRenderPassFunc)							GET_PROC_ADDR("vkCmdBeginRenderPass");
m_vk.cmdNextSubpass								= (CmdNextSubpassFunc)								GET_PROC_ADDR("vkCmdNextSubpass");
m_vk.cmdEndRenderPass							= (CmdEndRenderPassFunc)							GET_PROC_ADDR("vkCmdEndRenderPass");
m_vk.cmdExecuteCommands							= (CmdExecuteCommandsFunc)							GET_PROC_ADDR("vkCmdExecuteCommands");
m_vk.bindBufferMemory2							= (BindBufferMemory2Func)							GET_PROC_ADDR("vkBindBufferMemory2");
if (!m_vk.bindBufferMemory2)
	m_vk.bindBufferMemory2						= (BindBufferMemory2Func)							GET_PROC_ADDR("vkBindBufferMemory2KHR");
m_vk.bindImageMemory2							= (BindImageMemory2Func)							GET_PROC_ADDR("vkBindImageMemory2");
if (!m_vk.bindImageMemory2)
	m_vk.bindImageMemory2						= (BindImageMemory2Func)							GET_PROC_ADDR("vkBindImageMemory2KHR");
m_vk.getDeviceGroupPeerMemoryFeatures			= (GetDeviceGroupPeerMemoryFeaturesFunc)			GET_PROC_ADDR("vkGetDeviceGroupPeerMemoryFeatures");
if (!m_vk.getDeviceGroupPeerMemoryFeatures)
	m_vk.getDeviceGroupPeerMemoryFeatures		= (GetDeviceGroupPeerMemoryFeaturesFunc)			GET_PROC_ADDR("vkGetDeviceGroupPeerMemoryFeaturesKHR");
m_vk.cmdSetDeviceMask							= (CmdSetDeviceMaskFunc)							GET_PROC_ADDR("vkCmdSetDeviceMask");
if (!m_vk.cmdSetDeviceMask)
	m_vk.cmdSetDeviceMask						= (CmdSetDeviceMaskFunc)							GET_PROC_ADDR("vkCmdSetDeviceMaskKHR");
m_vk.cmdDispatchBase							= (CmdDispatchBaseFunc)								GET_PROC_ADDR("vkCmdDispatchBase");
if (!m_vk.cmdDispatchBase)
	m_vk.cmdDispatchBase						= (CmdDispatchBaseFunc)								GET_PROC_ADDR("vkCmdDispatchBaseKHR");
m_vk.getImageMemoryRequirements2				= (GetImageMemoryRequirements2Func)					GET_PROC_ADDR("vkGetImageMemoryRequirements2");
if (!m_vk.getImageMemoryRequirements2)
	m_vk.getImageMemoryRequirements2			= (GetImageMemoryRequirements2Func)					GET_PROC_ADDR("vkGetImageMemoryRequirements2KHR");
m_vk.getBufferMemoryRequirements2				= (GetBufferMemoryRequirements2Func)				GET_PROC_ADDR("vkGetBufferMemoryRequirements2");
if (!m_vk.getBufferMemoryRequirements2)
	m_vk.getBufferMemoryRequirements2			= (GetBufferMemoryRequirements2Func)				GET_PROC_ADDR("vkGetBufferMemoryRequirements2KHR");
m_vk.getImageSparseMemoryRequirements2			= (GetImageSparseMemoryRequirements2Func)			GET_PROC_ADDR("vkGetImageSparseMemoryRequirements2");
if (!m_vk.getImageSparseMemoryRequirements2)
	m_vk.getImageSparseMemoryRequirements2		= (GetImageSparseMemoryRequirements2Func)			GET_PROC_ADDR("vkGetImageSparseMemoryRequirements2KHR");
m_vk.trimCommandPool							= (TrimCommandPoolFunc)								GET_PROC_ADDR("vkTrimCommandPool");
if (!m_vk.trimCommandPool)
	m_vk.trimCommandPool						= (TrimCommandPoolFunc)								GET_PROC_ADDR("vkTrimCommandPoolKHR");
m_vk.getDeviceQueue2							= (GetDeviceQueue2Func)								GET_PROC_ADDR("vkGetDeviceQueue2");
m_vk.createSamplerYcbcrConversion				= (CreateSamplerYcbcrConversionFunc)				GET_PROC_ADDR("vkCreateSamplerYcbcrConversion");
if (!m_vk.createSamplerYcbcrConversion)
	m_vk.createSamplerYcbcrConversion			= (CreateSamplerYcbcrConversionFunc)				GET_PROC_ADDR("vkCreateSamplerYcbcrConversionKHR");
m_vk.destroySamplerYcbcrConversion				= (DestroySamplerYcbcrConversionFunc)				GET_PROC_ADDR("vkDestroySamplerYcbcrConversion");
if (!m_vk.destroySamplerYcbcrConversion)
	m_vk.destroySamplerYcbcrConversion			= (DestroySamplerYcbcrConversionFunc)				GET_PROC_ADDR("vkDestroySamplerYcbcrConversionKHR");
m_vk.createDescriptorUpdateTemplate				= (CreateDescriptorUpdateTemplateFunc)				GET_PROC_ADDR("vkCreateDescriptorUpdateTemplate");
if (!m_vk.createDescriptorUpdateTemplate)
	m_vk.createDescriptorUpdateTemplate			= (CreateDescriptorUpdateTemplateFunc)				GET_PROC_ADDR("vkCreateDescriptorUpdateTemplateKHR");
m_vk.destroyDescriptorUpdateTemplate			= (DestroyDescriptorUpdateTemplateFunc)				GET_PROC_ADDR("vkDestroyDescriptorUpdateTemplate");
if (!m_vk.destroyDescriptorUpdateTemplate)
	m_vk.destroyDescriptorUpdateTemplate		= (DestroyDescriptorUpdateTemplateFunc)				GET_PROC_ADDR("vkDestroyDescriptorUpdateTemplateKHR");
m_vk.updateDescriptorSetWithTemplate			= (UpdateDescriptorSetWithTemplateFunc)				GET_PROC_ADDR("vkUpdateDescriptorSetWithTemplate");
if (!m_vk.updateDescriptorSetWithTemplate)
	m_vk.updateDescriptorSetWithTemplate		= (UpdateDescriptorSetWithTemplateFunc)				GET_PROC_ADDR("vkUpdateDescriptorSetWithTemplateKHR");
m_vk.getDescriptorSetLayoutSupport				= (GetDescriptorSetLayoutSupportFunc)				GET_PROC_ADDR("vkGetDescriptorSetLayoutSupport");
if (!m_vk.getDescriptorSetLayoutSupport)
	m_vk.getDescriptorSetLayoutSupport			= (GetDescriptorSetLayoutSupportFunc)				GET_PROC_ADDR("vkGetDescriptorSetLayoutSupportKHR");
m_vk.createSwapchainKHR							= (CreateSwapchainKHRFunc)							GET_PROC_ADDR("vkCreateSwapchainKHR");
m_vk.destroySwapchainKHR						= (DestroySwapchainKHRFunc)							GET_PROC_ADDR("vkDestroySwapchainKHR");
m_vk.getSwapchainImagesKHR						= (GetSwapchainImagesKHRFunc)						GET_PROC_ADDR("vkGetSwapchainImagesKHR");
m_vk.acquireNextImageKHR						= (AcquireNextImageKHRFunc)							GET_PROC_ADDR("vkAcquireNextImageKHR");
m_vk.queuePresentKHR							= (QueuePresentKHRFunc)								GET_PROC_ADDR("vkQueuePresentKHR");
m_vk.getDeviceGroupPresentCapabilitiesKHR		= (GetDeviceGroupPresentCapabilitiesKHRFunc)		GET_PROC_ADDR("vkGetDeviceGroupPresentCapabilitiesKHR");
m_vk.getDeviceGroupSurfacePresentModesKHR		= (GetDeviceGroupSurfacePresentModesKHRFunc)		GET_PROC_ADDR("vkGetDeviceGroupSurfacePresentModesKHR");
m_vk.acquireNextImage2KHR						= (AcquireNextImage2KHRFunc)						GET_PROC_ADDR("vkAcquireNextImage2KHR");
m_vk.createSharedSwapchainsKHR					= (CreateSharedSwapchainsKHRFunc)					GET_PROC_ADDR("vkCreateSharedSwapchainsKHR");
m_vk.getMemoryWin32HandleKHR					= (GetMemoryWin32HandleKHRFunc)						GET_PROC_ADDR("vkGetMemoryWin32HandleKHR");
m_vk.getMemoryWin32HandlePropertiesKHR			= (GetMemoryWin32HandlePropertiesKHRFunc)			GET_PROC_ADDR("vkGetMemoryWin32HandlePropertiesKHR");
m_vk.getMemoryFdKHR								= (GetMemoryFdKHRFunc)								GET_PROC_ADDR("vkGetMemoryFdKHR");
m_vk.getMemoryFdPropertiesKHR					= (GetMemoryFdPropertiesKHRFunc)					GET_PROC_ADDR("vkGetMemoryFdPropertiesKHR");
m_vk.importSemaphoreWin32HandleKHR				= (ImportSemaphoreWin32HandleKHRFunc)				GET_PROC_ADDR("vkImportSemaphoreWin32HandleKHR");
m_vk.getSemaphoreWin32HandleKHR					= (GetSemaphoreWin32HandleKHRFunc)					GET_PROC_ADDR("vkGetSemaphoreWin32HandleKHR");
m_vk.importSemaphoreFdKHR						= (ImportSemaphoreFdKHRFunc)						GET_PROC_ADDR("vkImportSemaphoreFdKHR");
m_vk.getSemaphoreFdKHR							= (GetSemaphoreFdKHRFunc)							GET_PROC_ADDR("vkGetSemaphoreFdKHR");
m_vk.cmdPushDescriptorSetKHR					= (CmdPushDescriptorSetKHRFunc)						GET_PROC_ADDR("vkCmdPushDescriptorSetKHR");
m_vk.cmdPushDescriptorSetWithTemplateKHR		= (CmdPushDescriptorSetWithTemplateKHRFunc)			GET_PROC_ADDR("vkCmdPushDescriptorSetWithTemplateKHR");
m_vk.createRenderPass2KHR						= (CreateRenderPass2KHRFunc)						GET_PROC_ADDR("vkCreateRenderPass2KHR");
m_vk.cmdBeginRenderPass2KHR						= (CmdBeginRenderPass2KHRFunc)						GET_PROC_ADDR("vkCmdBeginRenderPass2KHR");
m_vk.cmdNextSubpass2KHR							= (CmdNextSubpass2KHRFunc)							GET_PROC_ADDR("vkCmdNextSubpass2KHR");
m_vk.cmdEndRenderPass2KHR						= (CmdEndRenderPass2KHRFunc)						GET_PROC_ADDR("vkCmdEndRenderPass2KHR");
m_vk.getSwapchainStatusKHR						= (GetSwapchainStatusKHRFunc)						GET_PROC_ADDR("vkGetSwapchainStatusKHR");
m_vk.importFenceWin32HandleKHR					= (ImportFenceWin32HandleKHRFunc)					GET_PROC_ADDR("vkImportFenceWin32HandleKHR");
m_vk.getFenceWin32HandleKHR						= (GetFenceWin32HandleKHRFunc)						GET_PROC_ADDR("vkGetFenceWin32HandleKHR");
m_vk.importFenceFdKHR							= (ImportFenceFdKHRFunc)							GET_PROC_ADDR("vkImportFenceFdKHR");
m_vk.getFenceFdKHR								= (GetFenceFdKHRFunc)								GET_PROC_ADDR("vkGetFenceFdKHR");
m_vk.debugMarkerSetObjectTagEXT					= (DebugMarkerSetObjectTagEXTFunc)					GET_PROC_ADDR("vkDebugMarkerSetObjectTagEXT");
m_vk.debugMarkerSetObjectNameEXT				= (DebugMarkerSetObjectNameEXTFunc)					GET_PROC_ADDR("vkDebugMarkerSetObjectNameEXT");
m_vk.cmdDebugMarkerBeginEXT						= (CmdDebugMarkerBeginEXTFunc)						GET_PROC_ADDR("vkCmdDebugMarkerBeginEXT");
m_vk.cmdDebugMarkerEndEXT						= (CmdDebugMarkerEndEXTFunc)						GET_PROC_ADDR("vkCmdDebugMarkerEndEXT");
m_vk.cmdDebugMarkerInsertEXT					= (CmdDebugMarkerInsertEXTFunc)						GET_PROC_ADDR("vkCmdDebugMarkerInsertEXT");
m_vk.cmdDrawIndirectCountAMD					= (CmdDrawIndirectCountAMDFunc)						GET_PROC_ADDR("vkCmdDrawIndirectCountAMD");
m_vk.cmdDrawIndexedIndirectCountAMD				= (CmdDrawIndexedIndirectCountAMDFunc)				GET_PROC_ADDR("vkCmdDrawIndexedIndirectCountAMD");
m_vk.cmdDrawIndirectCountKHR					= (CmdDrawIndirectCountKHRFunc)						GET_PROC_ADDR("vkCmdDrawIndirectCountKHR");
m_vk.cmdDrawIndexedIndirectCountKHR				= (CmdDrawIndexedIndirectCountKHRFunc)				GET_PROC_ADDR("vkCmdDrawIndexedIndirectCountKHR");
m_vk.getMemoryWin32HandleNV						= (GetMemoryWin32HandleNVFunc)						GET_PROC_ADDR("vkGetMemoryWin32HandleNV");
m_vk.cmdProcessCommandsNVX						= (CmdProcessCommandsNVXFunc)						GET_PROC_ADDR("vkCmdProcessCommandsNVX");
m_vk.cmdReserveSpaceForCommandsNVX				= (CmdReserveSpaceForCommandsNVXFunc)				GET_PROC_ADDR("vkCmdReserveSpaceForCommandsNVX");
m_vk.createIndirectCommandsLayoutNVX			= (CreateIndirectCommandsLayoutNVXFunc)				GET_PROC_ADDR("vkCreateIndirectCommandsLayoutNVX");
m_vk.destroyIndirectCommandsLayoutNVX			= (DestroyIndirectCommandsLayoutNVXFunc)			GET_PROC_ADDR("vkDestroyIndirectCommandsLayoutNVX");
m_vk.createObjectTableNVX						= (CreateObjectTableNVXFunc)						GET_PROC_ADDR("vkCreateObjectTableNVX");
m_vk.destroyObjectTableNVX						= (DestroyObjectTableNVXFunc)						GET_PROC_ADDR("vkDestroyObjectTableNVX");
m_vk.registerObjectsNVX							= (RegisterObjectsNVXFunc)							GET_PROC_ADDR("vkRegisterObjectsNVX");
m_vk.unregisterObjectsNVX						= (UnregisterObjectsNVXFunc)						GET_PROC_ADDR("vkUnregisterObjectsNVX");
m_vk.cmdSetViewportWScalingNV					= (CmdSetViewportWScalingNVFunc)					GET_PROC_ADDR("vkCmdSetViewportWScalingNV");
m_vk.displayPowerControlEXT						= (DisplayPowerControlEXTFunc)						GET_PROC_ADDR("vkDisplayPowerControlEXT");
m_vk.registerDeviceEventEXT						= (RegisterDeviceEventEXTFunc)						GET_PROC_ADDR("vkRegisterDeviceEventEXT");
m_vk.registerDisplayEventEXT					= (RegisterDisplayEventEXTFunc)						GET_PROC_ADDR("vkRegisterDisplayEventEXT");
m_vk.getSwapchainCounterEXT						= (GetSwapchainCounterEXTFunc)						GET_PROC_ADDR("vkGetSwapchainCounterEXT");
m_vk.getRefreshCycleDurationGOOGLE				= (GetRefreshCycleDurationGOOGLEFunc)				GET_PROC_ADDR("vkGetRefreshCycleDurationGOOGLE");
m_vk.getPastPresentationTimingGOOGLE			= (GetPastPresentationTimingGOOGLEFunc)				GET_PROC_ADDR("vkGetPastPresentationTimingGOOGLE");
m_vk.cmdSetDiscardRectangleEXT					= (CmdSetDiscardRectangleEXTFunc)					GET_PROC_ADDR("vkCmdSetDiscardRectangleEXT");
m_vk.setHdrMetadataEXT							= (SetHdrMetadataEXTFunc)							GET_PROC_ADDR("vkSetHdrMetadataEXT");
m_vk.cmdSetSampleLocationsEXT					= (CmdSetSampleLocationsEXTFunc)					GET_PROC_ADDR("vkCmdSetSampleLocationsEXT");
m_vk.createValidationCacheEXT					= (CreateValidationCacheEXTFunc)					GET_PROC_ADDR("vkCreateValidationCacheEXT");
m_vk.destroyValidationCacheEXT					= (DestroyValidationCacheEXTFunc)					GET_PROC_ADDR("vkDestroyValidationCacheEXT");
m_vk.mergeValidationCachesEXT					= (MergeValidationCachesEXTFunc)					GET_PROC_ADDR("vkMergeValidationCachesEXT");
m_vk.getValidationCacheDataEXT					= (GetValidationCacheDataEXTFunc)					GET_PROC_ADDR("vkGetValidationCacheDataEXT");
m_vk.getAndroidHardwareBufferPropertiesANDROID	= (GetAndroidHardwareBufferPropertiesANDROIDFunc)	GET_PROC_ADDR("vkGetAndroidHardwareBufferPropertiesANDROID");
m_vk.getMemoryAndroidHardwareBufferANDROID		= (GetMemoryAndroidHardwareBufferANDROIDFunc)		GET_PROC_ADDR("vkGetMemoryAndroidHardwareBufferANDROID");
