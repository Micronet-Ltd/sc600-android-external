#!/usr/bin/python
#
# Program that converts a NIST test vector RSP file to a C header
# file.  Currently only tested with the ExtendedIV GCM test vectors.
#
import argparse
import itertools


def _parse_args():
  parser = argparse.ArgumentParser()
  parser.add_argument("-i", "--in", dest="input_files",
                      help="Comma separated list of input RSP files",
                      metavar="FILE.rsp", required=True)
  parser.add_argument("-o", "--out", dest="output_file",
                      help="Output C header file", metavar="FILE.h",
                      required=True)
  return parser.parse_args()


def _read_nist_header(lines):
  """Parse a HEADER block, of form:
  [A = NUM1]
  [B = NUM2]
  \n
  """
  header = None  # {KEY1: INT1, KEY2: INT2, ...}
  while lines:
    line = lines.pop(0)
    if not line:
      return header
    if line.startswith('['):
      if not header:
        header = {}
      key, value = line.strip('][').split('=')
      header[key.strip()] = int(value.strip())
    else:
      raise Exception('Invalid header block line: %s' % line)
  return header


def _read_nist_blocks(lines):
  """Parse a DATA block, of form:
  A = HEX1
  B = HEX2
  \n
  """
  blocks = []  # [{KEY1: HEXSTR1, KEY2: HEXSTR2, ...}
  while lines:
    line = lines[0]
    if not line:
      # Block not started, ignore blank line.
      lines.pop(0)
      continue
    if line.startswith('[') or line.startswith('#'):
      # Next header encountered.
      break
    # Read a block.
    block = {}
    while lines:
      line = lines.pop(0)
      if not line:
        # End of block.
        break
      if '=' not in line:
        raise Exception('Unexpected line: %s' % line)
      key, value = line.split('=')
      block[key.strip()] = value.strip()
    blocks.append(block)
  return blocks


def _load_nist(infile):
  lines = infile.readlines()
  lines = [l.strip() for l in lines]
  data = []   # [(header1: [block1, block2]), (header2: ...)]
  mode = lines[1].split(' ')[1]

  while lines:
    line = lines[0]
    if not line or line.startswith('#'):
      # Ignore blank lines or comments.
      lines.pop(0)
      continue
    if not line.startswith('['):
      raise Exception('Header not found: %s' % line)
    header = _read_nist_header(lines)
    blocks = _read_nist_blocks(lines)
    data.append((header, blocks))
  return mode, data


def _words32(v):
  # Split hex string into 32-bit words.
  args = [iter(v)] * 8
  words = [''.join(b) for b in itertools.izip_longest(fillvalue='', *args)]
  return map(lambda w: w.ljust(8, '0'), words)    # Zero-pad the last word.


def _bswap32(w):
  if len(w) != 8:
    raise Exception('Expected 32-bit input word, got: %s' % w)
  w = w[::-1]   # Reverse hex string.
  w = iter(w)
  return ''.join([b2 + b1 for b1, b2 in itertools.izip(w, w)])


def _format32(block):
  # Format values into 32-bit words, with appropriate endienness.
  b = {}
  for k, v in block.iteritems():
    if k == 'Count':
      b[k] = v
      continue
    if not v:    # Strip keys with empty values.
      continue
    v = ', '.join(['0x%s' % _bswap32(w) for w in _words32(v)])
    b[k] = '{%s}' % v
  return b


def _write_header(input_files, outfile, mode, data):
  outfile.write('/*\n * Auto generated by nist2h.py from input files:\n')
  for fname in input_files.split(','):
    outfile.write(' *     %s\n' % fname)
  outfile.write(' */\n')
  outfile.write('#ifndef AES_%s_CAVP_H\n' % mode)
  outfile.write('#define AES_%s_CAVP_H\n' % mode)
  outfile.write('''
typedef struct {
    uint32_t key[8];
    uint32_t key_len;
    uint32_t IV[128];
    uint32_t IV_len;
    uint32_t PT[64];
    uint32_t PT_len;
    uint32_t CT[64];
    uint32_t AAD[96];
    uint32_t AAD_len;
    uint32_t tag[16];
    uint32_t tag_len;
} %s_data;

''' % mode.lower())
  outfile.write('const %s_data NIST_%s_DATA[] = {\n' % (mode.lower(), mode))
  for i, entry in enumerate(data):
    header, blocks = entry
    for block in blocks:
      block = _format32(block)
      AAD = '{}'
      AAD_len = 0
      if 'AAD' in block:
        AAD = block['AAD']
        AAD_len = header['AADlen']
      PT = '{}'
      PT_len = 0
      if 'PT' in block:
        PT = block['PT']
        PT_len = header['PTlen']
      CT = '{}'
      if 'CT' in block:
        CT = block['CT']

      line = ('{key}, {key_len}, {IV}, {IV_len}, {PT}, {PT_len}, '
              '{CT}, {AAD}, {AAD_len}, {tag}, {tag_len}').format(
                  key=block['Key'], key_len=header['Keylen'], IV=block['IV'],
                  IV_len=header['IVlen'], PT=PT, PT_len=PT_len, CT=CT, AAD=AAD,
                  AAD_len=AAD_len, tag=block['Tag'], tag_len=header['Taglen'])
      outfile.write('    {%s},\n' % line)
  outfile.write('};\n\n')
  outfile.write('#endif /* ! AES_TESTS_%s_DATA_H */\n' % mode)


if __name__ == '__main__':
  args = _parse_args()
  data = []
  for input_file in args.input_files.split(','):
    print 'Processing:', input_file
    with open(input_file) as f:
      mode, loaded_data = _load_nist(f)
      data.extend(loaded_data)
  with open(args.output_file, 'w+') as f:
    _write_header(args.input_files, f, mode, data)