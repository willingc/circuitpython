# Adafruit's CircuitPython Documentation

The latest CircuitPython API Reference documentation can be found at Read The
Docs: http://circuitpython.readthedocs.io/en/latest/

## Source files for documentation

The documentation is generated from the source files in the whole git tree:
https://github.com/adafruit/circuitpython/tree/master

## Building the documentation locally

If you're making changes to the documentation, you should build the
documentation locally so that you can preview your changes.

Install Sphinx, recommonmark, and optionally (for the RTD-styling), sphinx_rtd_theme,
preferably in a virtualenv:

     pip install sphinx
     pip install recommonmark
     pip install sphinx_rtd_theme

In the `circuitpython` root directory, enter this command to build the docs:

    sphinx-build -v -b html . _build/html

You'll find the index page at `_build/html/index.html`.
