# Configuration file for the Sphinx documentation builder.
# This file only contains a selection of the most common options.
# For a full list see the documentation: http://www.sphinx-doc.org/en/master/usage/configuration.html

# All configurations have a default
# If you empty this file, Sphinx will still work well :))

# -- PROJECT INFORMATION -----------------------------------------------------
project = 'test'
copyright = '2019, tri'
author = 'tri'
# The short X.Y version
version = ''
# The full version, including alpha/beta/rc tags
release = '1.0'

# -- GENERAL CONFIGURATION ---------------------------------------------------
# Add any Sphinx extension module names here, as strings. 
# They can be extensions coming with Sphinx (named 'sphinx.ext.*') or external extensions.
# Directory /sphinx/ext/ locates on folder where you installed Sphinx
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.doctest',
]

# File extensions of source files (mostly .rst or .txt)
# You can specify multiple suffix as a list of string.
source_suffix = '.rst'

# Thi is the document containing the root toctree directive.
# Default is 'index'.
master_doc = 'index'

# A list of paths that contain extra templates (or templates that overwrite builtin/theme-specific templates). 
# Relative paths are taken as relative to the configuration directory.
templates_path = ['_templates']

# -- OPTIONS FOR HTML OUTPUT -------------------------------------------------
# The theme that the HTML output will use
# http://www.sphinx-doc.org/en/master/usage/theming.html
html_theme = 'alabaster'

# A list of paths that contain custom static files (such as style sheets or script files). 
# Relative paths are taken as relative to the configuration directory. 
# They are copied to the output’s _static directory after the theme’s static files, 
# so a file named default.css will overwrite the theme’s default.css.
# As these files are not meant to be built, they are automatically excluded from source files.
html_static_path = ['_static']

# -- OPTIONS FOR LATEX OUTPUT ------------------------------------------------
latex_elements = {
    # The paper size ('letterpaper' or 'a4paper')
    # 'papersize': 'letterpaper',

    # The font size ('10pt', '11pt' or '12pt')
    # 'pointsize': '10pt',

    # Additional stuff for the LaTeX preamble
    # 'preamble': '',

    # Latex figure (float) alignment
    # 'figure_align': 'htbp',
}

# Grouping the document tree into LaTeX files.
# List of tuples (source start file, target name, title,
# author, documentclass [howto, manual, or own class]).
latex_documents = [
    (master_doc,
    'Sample.tex',
    u'Sample Documentation',
    u'Tri',
    'manual'),
]

# Hide html sidebar
html_sidebars = {'**': []}