
from PIL import Image


def has_valid_size(img):
    w, h = img.size
    return h % 8 == 0 and w % 8 == 0


def format_img_palette(img, colors=16):
    not_formatted = img.getpalette()
    formated = [[255, 0, 255]] * colors
    for i in range(colors):
        formated[i] = not_formatted[i * 3: (i + 1) * 3]
    return formated


def img_to_gba_16colors(img):
    data = b''
    imgdata = img.getdata()
    w, h = img.size
    tiles_h, tiles_w = h // 8, w // 8
    for tile in range(tiles_h * tiles_w):
        tile_data = b''
        index = 8 * (tile % tiles_w) + w * 8 * (tile // tiles_w)
        for j in range(8):
            for i in range(4):
                n = imgdata[index + 2*i + j*w] | (imgdata[index + 2*i + j*w + 1] << 4)
                tile_data += n.to_bytes(1, 'little')

        data += tile_data
    return data


def img_palette_to_gba(img):
    formatted = format_img_palette(img)
    return pal_to_gba(formatted)


def pal_to_gba(palette):
    data = b''
    for color in palette:
        r, g, b = color
        r >>= 3
        g >>= 3
        b >>= 3
        data += (r | (g << 5) | (b << 10)).to_bytes(2, 'little')
    return data


if __name__ == '__main__':
    import lz77
    img = Image.open('../char.png')
    with open('../bpre.gba', 'rb+') as f:
        d = img_to_gba_16colors(img)
        f.seek(0x800000)

        f.write(lz77.compress(d))
        f.seek(0x900000)
        d = format_img_palette(img)
        f.write(lz77.compress(pal_to_gba(d)))

