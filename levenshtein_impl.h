/*
 * Levenshtein distance using the classic DP algorithm.
 * Copyright 2013 Lars Buitinck.
 * All rights reserved. See the file LICENSE for licensing information.
 */

#ifndef levenshtein_impl_h
#define levenshtein_impl_h

#include <algorithm>
#include <climits>
#include <stdexcept>
#include <vector>

static unsigned min(unsigned a, unsigned b, unsigned c)
{
    return std::min(a, std::min(b, c));
}

template <typename Char>
static unsigned levenshtein(Char const *a, size_t m, Char const *b, size_t n)
{
    // Swap a and b if necessary to ensure m <= n.
    if (m > n) {
        Char const *p;
        size_t t;

        p = a;
        a = b;
        b = p;

        t = m;
        m = n;
        n = t;
    }

    // Skip common prefix.
    while (*a == *b) {
        a++, b++;
        m--, n--;
    }

    // Skip common suffix.
    while (m > 0 && n > 0 && a[m - 1] == b[n - 1]) {
        m--, n--;
    }

    // To save memory, we use unsigned as the type in the DP table.
    if (m > UINT_MAX || n > UINT_MAX) {
        throw std::length_error("string too long in Levenshtein distance.");
    }

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    std::vector<unsigned> tab((m + 1) * 2);

    unsigned *cur = tab.data(), *prev = tab.data() + m + 1;

    for (size_t i = 0; i <= m; i++) {
        cur[i] = i;
    }
    for (size_t j = 1; j <= n; j++) {
        unsigned *t = cur;
        cur = prev;
        prev = t;

        cur[0] = j;

        for (size_t i = 1; i <= m; i++) {
            if (a[i - 1] == b[j - 1]) {
                cur[i] = prev[i - 1];
            }
            else {
                cur[i] = min(cur[i - 1], prev[i], prev[i - 1]) + 1;
            }
        }
    }

    return cur[m];
}

#endif  // levenshtein_impl_h
