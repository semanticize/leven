from distutils.core import setup
from Cython.Build import cythonize

setup(
    name='leven',
    version='1.0',
    description='Levenshtein edit distance library',
    maintainer='Lars Buitinck',
    maintainer_email='l.j.buitinck@esciencecenter.nl',
    packages=['leven'],
    ext_modules=cythonize("leven/_levenshtein.pyx", language="c++"),
    install_requires=["six", "nose"],
    url='https://github.com/semanticize/leven',
)
