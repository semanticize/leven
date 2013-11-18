# Copyright 2013 Netherlands eScience Center
# Written by Lars Buitinck
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# distutils: language = c++

from cpython cimport PyUnicode_AS_UNICODE, PyUnicode_GET_SIZE


cdef extern from "levenshtein_types.h":
    int levenshtein_char(const char *, size_t, const char *, size_t) except +
    int levenshtein_Py_UNICODE(const Py_UNICODE *, size_t,
                               const Py_UNICODE *, size_t) except +


def levenshtein(a, b, normalize=False):
    """Returns the Levenshtein (edit) distance between a and b.

    When a and b are both byte strings (type bytes), the distance is computed
    bytewise. When a and b are both Unicode strings (type unicode in Python 2,
    str in Python 3), the distance is computed codepoint-wise.

    Other combinations of types will cause a TypeError to be raised.

    When passing Unicode strings, make sure they use the same normalized form
    (use the function unicodedata.normalize in the standard library).

    The normalize parameter can be used to normalize the distance by the length
    of the longest input.

    Example
    -------
    >>> levenshtein("Python", "Schmython")
    4
    """
    cdef int d
    cdef size_t m = len(a), n = len(b)

    if isinstance(a, bytes) and isinstance(b, bytes):
        d = levenshtein_char(a, m, b, n)
    elif isinstance(a, unicode) and isinstance(b, unicode):
        d = levenshtein_Py_UNICODE(PyUnicode_AS_UNICODE(a), m,
                                   PyUnicode_AS_UNICODE(b), n)
    else:
        raise TypeError("Type mismatch: expected (bytes, bytes) or ({0}, {0}),"
                        " got ({1}, {2})".format(unicode, type(a), type(b)))

    if normalize:
        return <double>(d) / <double>(max(m, n, 1))
    else:
        return d
