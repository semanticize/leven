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


def levenshtein_unicode(a, b):
    return levenshtein_Py_UNICODE(PyUnicode_AS_UNICODE(a), len(a),
                                  PyUnicode_AS_UNICODE(b), len(b))
