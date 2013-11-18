from distutils.core import setup
from Cython.Build import cythonize

setup(
    name='leven',
    maintainer='Lars Buitinck',
    packages=['leven'],
    ext_modules=cythonize("leven/_levenshtein.pyx", language="c++"),
    install_requires=["six", "nose"],
)
