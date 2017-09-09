"""Helper to parse C comments to RestructuredText"""
import docutils.parsers
import docutils.parsers.rst as rst

class CStrip(docutils.parsers.Parser):
    """Strip comment prefixes from C comments

    TODO: determine if sphinx parser could work

    """
    def __init__(self):
        self.rst_parser = rst.Parser()

    def parse(self, inputstring, document):
        """Strip comment indicators from a string and place in a document."""
        stripped = []

        # iterate through individual lines of text
        for line in inputstring.split('\n'):
            # strip leading and trailing characters
            line = line.strip()
            if line == '//|':
                stripped.append('')
            elif line.startswith('//| '):
                stripped.append(line[len("//| "):])

        stripped = "\r\n".join(stripped)
        self.rst_parser.parse(stripped, document)
