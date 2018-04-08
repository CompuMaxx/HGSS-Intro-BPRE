# -*- coding: utf-8 -*-

to_int = lambda x: int.from_bytes(x, "little")


class InvalidLz77Data(Exception):
    pass


def decompress(compressed_data):
    '''Decompresses lz77-compressed images in GBA ROMs.
       Algorithm originally ported from NLZ-Advance code
       (which has copyright by Nintenlord)
       compressed data must be either a bytes() or a bytearray()
       (this function was ported to python by cosarara97)'''
    size = to_int(compressed_data[1:4])
    decompressed_data = bytearray(size)
    if compressed_data[0] != 0x10:
        raise InvalidLz77Data('Not valid lz77 data')
    decomp_pos = 0
    comp_pos = 4
    while decomp_pos < size:
        # Every bit of this byte maps to one of the eight following blocks
        # if the bit is 1, that block is compressed
        byte = compressed_data[comp_pos]
        are_compressed = [(byte >> 7-i) & 1 for i in range(8)]
        comp_pos += 1
        # for block_i, is_compressed in enumerate(are_compressed):
        for is_compressed in are_compressed:
            if is_compressed:
                amount_to_copy = 3 + (compressed_data[comp_pos]>>4)
                to_copy_from = (1 +
                                ((compressed_data[comp_pos] & 0xF) << 8) +
                                compressed_data[comp_pos + 1])
                if to_copy_from > size:
                    raise Exception('Not valid lz77 data')
                tmp_start = decomp_pos - to_copy_from
                #tmp_start = decomp_pos
                for i in range(amount_to_copy):
                    if decomp_pos >= size:
                        break
                    decompressed_data[decomp_pos] = decompressed_data[
                        tmp_start + i
                        #tmp_start - to_copy_from + i
                    ]
                    decomp_pos += 1
                comp_pos += 2

            else:
                if decomp_pos >= size:
                    break
                decompressed_data[decomp_pos] = compressed_data[comp_pos]
                decomp_pos += 1
                comp_pos += 1
            if decomp_pos > size:
                break
    return decompressed_data, comp_pos  # comp_pos contains the size of the compressed data


def search_repeated_bytes(data, position, size):
    """
    This was also taken from NLZ-Advance
    and optimized for python
    """
    if position < 3 or (size - position) < 3:
        return 0, 0
    elif position >= size:
        return -1, 0

    result = None
    for i in range(3, 19):
        f_res = data.find(data[position:position + 1 + i], max(0, position - 0x1000), position)
        if f_res != -1:
            result = (i, (position - f_res))
        else:
            break
    if result is None:
        return 0, 0
    else:
        return result


def compress(data):
    """
    And this too!
    Thanks Nintenlord!
    """
    size = len(data)
    position = 0
    compressed_data = b'\x10' + size.to_bytes(3, 'little')

    while position < size:
        blocks_compress_flags = 0
        block_data = b''
        i = 0
        while i < 8 and position < size:
            search_result = search_repeated_bytes(data, position, size)
            if search_result[0] > 2:
                block_data += (((search_result[0] - 3) << 12) |
                               (search_result[1] - 1)).to_bytes(2, 'big')
                position += search_result[0]

                blocks_compress_flags |= 1 << (7 - i)
            elif search_result[0] >= 0:
                block_data += data[position:position + 1]
                position += 1
            else:
                break
            i += 1

        compressed_data += blocks_compress_flags.to_bytes(1, 'little') + block_data

    compressed_data += b'\x00' * (0, 3, 2, 1)[len(compressed_data) % 4]

    return compressed_data


