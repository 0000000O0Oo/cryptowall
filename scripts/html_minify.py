import htmlmin

with open('../pages/index.html') as fin:
    minified = htmlmin.minify(fin.read(), remove_empty_space=True)
    with open('index_new.html', 'w') as fout:
        fout.write(minified.replace('\n', ''))
