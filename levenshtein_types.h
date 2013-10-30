// Work around lack of template functions in Cython.

#include "levenshtein_impl.h"

int levenshtein_char(char const *a, size_t m, char const *b, size_t n)
{
    return levenshtein(a, m, b, n);
}

int levenshtein_Py_UNICODE(Py_UNICODE const *a, size_t m,
                           Py_UNICODE const *b, size_t n)
{
    return levenshtein(a, m, b, n);
}
