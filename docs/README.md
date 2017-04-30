Adafruit's CircuitPython Documentation
======================================

The latest documentation can be found at:
http://circuitpython.readthedocs.io/en/latest/

The documentation you see there is generated from the files in the whole tree:
https://github.com/adafruit/circuitpython/tree/master

Building the documentation locally
----------------------------------

If you're making changes to the documentation, you should build the
documentation locally so that you can preview your changes.

### Create and activate a virtualenv (optional)

You may choose to create a virtualenv which is used like
a sandbox to keep dependencies from interfering with other projects. In
Python3, you create a virtualenv by entering:

    python3 -m venv my_virtualenv
    
To use the virtual environment, you must first activate it:

    source my_virtualenv/bin/activate
    
If the virtual environment is activated you will see `(my_virtualenv)`
near the command prompt.
 
### Install dependencies    
    
To install dependencies for documentation, change to the `docs` directory
and enter:

    pip install -r docs/requirements-doc.txt

### Build documentation

To build the docs from the root directory of the repository:

    sphinx-build -v -b html . _build/html

All the built html files can be found in the `_build/html` directory.

### View documentation interactively

You can start a webserver to view the documentation interactively:

    python3 -m http.server

In your browser, you'll find the documentation index page at
`http://127.0.0.1:8000/_build/html/index.html`.

### Deactivate a virtualenv (optional)

When done working with the documentation, deactivate the virtualenv by
entering:

    deactivate
