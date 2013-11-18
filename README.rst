Leven
=====

Levenshtein edit distance library for Python, Apache-licensed.
Written by Lars Buitinck, Netherlands eScience Center.

Performs distance computations on either byte strings or Unicode codepoints.

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
