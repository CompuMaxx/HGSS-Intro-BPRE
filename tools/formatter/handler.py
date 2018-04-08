
from PIL import Image
import os

from . import gba_image
from . import lz77


BASE_HEADER = '\n\n#ifndef {0}\n#define {0}\n\n#endif // {0}'


class HandlerError(Exception):
    pass


def validate_img(img_path):
    try:
        img = Image.open(img_path)
    except FileNotFoundError:
        raise HandlerError('The file "{}" doesn\'t exist.')
    if img.mode != 'P':
        raise HandlerError('Image file is not indexed.')
    elif not gba_image.has_valid_size(img):
        raise HandlerError('Invalid image size.')

    return img


def format_data(name, data):
    i = 0
    hex_array_values = ''
    for byte in data:
        if i == 0:
            hex_array_values += '\n   '
        hex_array_values += ' {},'.format(hex(byte))
        if i == 7:
            i = 0
        else:
            i += 1

    ret = 'const unsigned char {0}[{1}] __attribute__((aligned(4))) =\n'.format(name, len(data))
    ret += '{' + hex_array_values + '\n};\n'
    return ret


class FormatterHandler:
    def __init__(self):
        self.names = []
        self.consts = []

    def remove_const(self, index):
        del self.names[index], self.consts[index]

    def add_const(self, name, data):
        if name in self.names:
            raise HandlerError('There is already a constant named "{}".'.format(name))
        self.names.append(name)
        self.consts.append(format_data(name, data))

    def add_const_from_img(self, name, img_path, bool_get_img, bool_get_pal, bool_compressed):
        img = validate_img(img_path)
        if bool_get_img:
            self.add_imgdata_const(name, img, bool_compressed)
        if bool_get_pal:
            self.add_paldata_const(name, img, bool_compressed)

    def add_imgdata_const(self, name, img, bool_compressed):
        data = gba_image.img_to_gba_16colors(img)
        if bool_compressed:
            data = lz77.compress(data)
        self.add_const('{}_img'.format(name), data)

    def add_paldata_const(self, name, img, bool_compressed):
        data = gba_image.img_palette_to_gba(img)
        if bool_compressed:
            data = lz77.compress(data)
        self.add_const('{}_pal'.format(name), data)

    def add_const_from_raw(self, name, filename, bool_compressed):
        with open(filename, 'rb') as f:
            data = f.read()
        if bool_compressed:
            data = lz77.compress(data)
        self.add_const('{}_raw'.format(name), data)

    def format_header(self, name):
        consts = ''
        for const in self.consts:
            consts += '{0}\n'.format(const)
        header_def = name.replace('.', '_')
        return '\n\n#ifndef {0}\n#define {0}\n\n{1}\n\n#endif // {0}'.format(header_def, consts)

    def save_header(self, filename):
        name = os.path.basename(filename)
        with open(filename, 'w') as f:
            f.write(self.format_header(name))
        return filename

