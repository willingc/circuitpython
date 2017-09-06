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

Create and activate a virtual environment:

```bash
    cd docs
    python3 venv mydocenv
    source mydocenv/bin/activate
```

From the `docs` directory, install requirements:

```bash
    python3 -m pip install -r requirements-doc.txt
```

In `circuitpython/docs` directory, build the docs:

```
   make clean
   make html
```

You'll find the index page at `build/html/index.html`.
