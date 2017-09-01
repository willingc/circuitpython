# Contributing to Adafruit's CircuitPython Documentation

The [latest CircuitPython API Reference documentation][] can be found at Read
The Docs.

## Source files for documentation

This CircuitPython documentation is generated from the [source files][] for
CircuitPython on GitHub.

## Contributing to documentation

If you are interested in contributing to the documentation or making changes
to the existing documentation, you should set up a local development
environment. This will help you build the documentation locally so that you
can preview your changes.

## Set up a development environment

These instructions are based on using Python 3.5 or higher.

#. Create and activate a virtual environment

    ```bash
    python -m venv mydocenv
    source mydocenv/bin/activate
    ```

    If you have correctly activated the virtual environment, you will see
    `(mydocenv)` at the start of the prompt in the terminal.

#. Install documentation dependencies

   From the root directory of CircuitPython, install the doc requirements:

   ```bash
   pip install -r requirements.txt
   ```

#. Build the documentation locally

   In the `circuitpython/docs` directory, enter this command to build the 
   docs:

   ```bash
   sphinx-build -v -b html . _build/html
   ```

#. View the documentation locally

   You'll find the index page for the documentation at `_build/html/index.html`.

   You can view the file above in your browser by entering:

   ```bash
   open _build/html/index.html
   ```

   Alternatively, you could start a webserver by entering and following the
   direction in its output to enter a URL in the browser:

   ```bash
   python -m http.server
   ```

[latest CircuitPython API Reference documentation]: http://circuitpython.readthedocs.io/en/latest/
[source files]: https://github.com/adafruit/circuitpython/tree/master
