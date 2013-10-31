# distutils: language = c++

from cpython cimport PyUnicode_AS_UNICODE, PyUnicode_GET_SIZE


cdef extern from "levenshtein_types.h":
    int levenshtein_char(const char *, size_t, const char *, size_t) except +
    int levenshtein_Py_UNICODE(const Py_UNICODE *, size_t,
                               const Py_UNICODE *, size_t) except +


def levenshtein_unicode(a, b):
    return levenshtein_Py_UNICODE(PyUnicode_AS_UNICODE(a), len(a),
                                  PyUnicode_AS_UNICODE(b), len(b))
