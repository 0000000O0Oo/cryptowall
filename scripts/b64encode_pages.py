#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import base64

if __name__ == '__main__':
    files_to_encode = ['index_new.html', '../pages/styles.css', '../pages/logo.png']

    for filename in files_to_encode:
        print('[*] Encoding: {}'.format(filename))
        with open(filename, 'rb') as fin:
            with open(filename.split('/')[-1:][0] + '.b64', 'w') as fout:
                fout.write(str(base64.b64encode(fin.read())))
