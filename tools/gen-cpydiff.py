# This file is part of the MicroPython project, http://micropython.org/
#
# The MIT License (MIT)
#
# Copyright (c) 2016 Rami Ali
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

""" gen-cpydiff generates documentation which outlines operations that differ between MicroPython
    and CPython. This script is called by the docs Makefile for html and Latex and may be run
    manually using the command make gen-cpydiff. """

import os
import errno
import subprocess
import time
import re
from collections import namedtuple

# MicroPython supports syntax of CPython 3.4 with some features from 3.5, and
# such version should be used to test for differences. If your default python3
# executable is of lower version, you can point MICROPY_CPYTHON3 environment var
# to the correct executable.
if os.name == 'nt':
    CPYTHON3 = os.getenv('MICROPY_CPYTHON3', 'python3.exe')
    MICROPYTHON = os.getenv('MICROPY_MICROPYTHON', '../windows/micropython.exe')
else:
    CPYTHON3 = os.getenv('MICROPY_CPYTHON3', 'python3')
    MICROPYTHON = os.getenv('MICROPY_MICROPYTHON', '../unix/micropython')

TESTPATH = '../tests/cpydiff/'
DOCPATH = '../docs_circuitpython/genrst/'
INDEXTEMPLATE = '../docs_circuitpython/differences/index_template.txt'
INDEX = 'index.rst'

HEADER = '.. This document was generated by tools/gen-cpydiff.py\n\n'
UIMPORTLIST = {'struct', 'collections', 'json'}
CLASSMAP = {'Core': 'Core Language', 'Types': 'Builtin Types'}
INDEXPRIORITY = ['syntax', 'core_language', 'builtin_types', 'modules']
RSTCHARS = ['=', '-', '~', '`', ':']
SPLIT = '"""\n|categories: |description: |cause: |workaround: '
TAB = '    '

Output = namedtuple('output', ['name', 'class_', 'desc', 'cause', 'workaround', 'code',
                               'output_cpy', 'output_upy', 'status'])

def readfiles():
    """ Reads test files """
    tests = list(filter(lambda x: x.endswith('.py'), os.listdir(TESTPATH)))
    tests.sort()
    files = []

    for test in tests:
        text = open(TESTPATH + test, 'r').read()

        try:
            class_, desc, cause, workaround, code = [x.rstrip() for x in \
                                                    list(filter(None, re.split(SPLIT, text)))]
            output = Output(test, class_, desc, cause, workaround, code, '', '', '')
            files.append(output)
        except IndexError:
            print('Incorrect format in file ' + TESTPATH + test)

    return files

def uimports(code):
    """ converts CPython module names into MicroPython equivalents """
    for uimport in UIMPORTLIST:
        uimport = bytes(uimport, 'utf8')
        code = code.replace(uimport, b'u' + uimport)
    return code

def run_tests(tests):
    """ executes all tests """
    results = []
    for test in tests:
        with open(TESTPATH + test.name, 'rb') as f:
            input_cpy = f.read()
        input_upy = uimports(input_cpy)

        process = subprocess.Popen(CPYTHON3, shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE)
        output_cpy = [com.decode('utf8') for com in process.communicate(input_cpy)]

        process = subprocess.Popen(MICROPYTHON, shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE, stderr=subprocess.PIPE)
        output_upy = [com.decode('utf8') for com in process.communicate(input_upy)]

        if output_cpy[0] == output_upy[0] and output_cpy[1] == output_upy[1]:
            status = 'Supported'
            print('Supported operation!\nFile: ' + TESTPATH + test.name)
        else:
            status = 'Unsupported'

        output = Output(test.name, test.class_, test.desc, test.cause,
                        test.workaround, test.code, output_cpy, output_upy, status)
        results.append(output)

    results.sort(key=lambda x: x.class_)
    return results

def indent(block, spaces):
    """ indents paragraphs of text for rst formatting """
    new_block = ''
    for line in block.split('\n'):
        new_block += spaces + line + '\n'
    return new_block

def gen_table(contents):
    """ creates a table given any set of columns """
    xlengths = []
    ylengths = []
    for column in contents:
        col_len = 0
        for entry in column:
            lines = entry.split('\n')
            for line in lines:
                col_len = max(len(line) + 2, col_len)
        xlengths.append(col_len)
    for i in range(len(contents[0])):
        ymax = 0
        for j in range(len(contents)):
            ymax = max(ymax, len(contents[j][i].split('\n')))
        ylengths.append(ymax)

    table_divider = '+' + ''.join(['-' * i + '+' for i in xlengths]) + '\n'
    table = table_divider
    for i in range(len(ylengths)):
        row = [column[i] for column in contents]
        row = [entry + '\n' * (ylengths[i]-len(entry.split('\n'))) for entry in row]
        row = [entry.split('\n') for entry in row]
        for j in range(ylengths[i]):
            k = 0
            for entry in row:
                width = xlengths[k]
                table += ''.join(['| {:{}}'.format(entry[j], width - 1)])
                k += 1
            table += '|\n'
        table += table_divider
    return table + '\n'

def gen_rst(results):
    """ creates restructured text documents to display tests """

    # make sure the destination directory exists
    try:
        os.mkdir(DOCPATH)
    except OSError as e:
        if e.args[0] != errno.EEXIST and e.args[0] != errno.EISDIR:
            raise

    toctree = []
    class_ = []
    for output in results:
        section = output.class_.split(',')
        for i in range(len(section)):
            section[i] = section[i].rstrip()
            if section[i] in CLASSMAP:
                section[i] = CLASSMAP[section[i]]
            if i >= len(class_) or section[i] != class_[i]:
                if i == 0:
                    filename = section[i].replace(' ', '_').lower()
                    rst = open(DOCPATH + filename + '.rst', 'w')
                    rst.write(HEADER)
                    rst.write(section[i] + '\n')
                    rst.write(RSTCHARS[0] * len(section[i]))
                    rst.write(time.strftime("\nGenerated %a %d %b %Y %X UTC\n\n", time.gmtime()))
                    toctree.append(filename)
                else:
                    rst.write(section[i] + '\n')
                    rst.write(RSTCHARS[min(i, len(RSTCHARS)-1)] * len(section[i]))
                    rst.write('\n\n')
        class_ = section
        rst.write('.. _cpydiff_%s:\n\n' % output.name.rsplit('.', 1)[0])
        rst.write(output.desc + '\n')
        rst.write('~' * len(output.desc) + '\n\n')
        if output.cause != 'Unknown':
            rst.write('**Cause:** ' + output.cause + '\n\n')
        if output.workaround != 'Unknown':
            rst.write('**Workaround:** ' + output.workaround + '\n\n')

        rst.write('Sample code::\n\n' + indent(output.code, TAB) + '\n')
        output_cpy = indent(''.join(output.output_cpy[0:2]), TAB).rstrip()
        output_cpy = ('::\n\n' if output_cpy != '' else '') + output_cpy
        output_upy = indent(''.join(output.output_upy[0:2]), TAB).rstrip()
        output_upy = ('::\n\n' if output_upy != '' else '') + output_upy
        table = gen_table([['CPy output:', output_cpy], ['uPy output:', output_upy]])
        rst.write(table)

    template = open(INDEXTEMPLATE, 'r')
    index = open(DOCPATH + INDEX, 'w')
    index.write(HEADER)
    index.write(template.read())
    for section in INDEXPRIORITY:
        if section in toctree:
            index.write(indent(section + '.rst', TAB))
            toctree.remove(section)
    for section in toctree:
        index.write(indent(section + '.rst', TAB))

def main():
    """ Main function """

    # set search path so that test scripts find the test modules (and no other ones)
    os.environ['PYTHONPATH'] = TESTPATH
    os.environ['MICROPYPATH'] = TESTPATH

    files = readfiles()
    results = run_tests(files)
    gen_rst(results)

main()
