Leven
=====

Levenshtein edit distance library for Python, Apache-licensed.
Written by Lars Buitinck, Netherlands eScience Center, with contributions
from Isaac Sijaranamual, University of Amsterdam.

Performs distance computations on either byte strings or Unicode codepoints.

Installation
------------

Make sure you have Cython and a C++ compiler installed::

    pip install cython

Installing a C++ compiler is so platform-dependent that I won't show
instructions. Consult your package manager.

Then::

    python setup.py install

To run the tests, but not to actually use leven, you need six and Nose.

Usage
-----

    >>> from leven import levenshtein
    >>> levenshtein("hello, world!", "goodbye, cruel world!")
    13

About the implementation
------------------------

The core algorithms have been implemented in C++. I used this instead of C
to get templates, easier memory management and a better standard library,
so the C++ code probably looks C-ish.

Todo
----

* Implement Ukkonen's algorithm for bounded Levenshtein distance
* Implement Levenshtein automata for fast neighbor search in string spaces
* Implement weighted Levenshtein distance
