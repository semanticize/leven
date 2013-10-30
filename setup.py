from distutils.core import setup
from Cython.Build import cythonize

setup(
    name='leven',
    ext_modules=cythonize("leven.pyx", language="c++"),
)
