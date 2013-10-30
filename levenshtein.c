/*
 * Levenshtein distance using the classic DP algorithm.
 */

#include <errno.h>
#include <limits.h>
#include <stdlib.h>

typedef char Char;

static int min2(int a, int b)
{
    return a < b ? a : b;
}

static int min3(int a, int b, int c)
{
    return min2(a, min2(b, c));
}

int levenshtein(Char const *a, size_t m, Char const *b, size_t n)
{
    // Swap a and b if necessary to ensure m < n.
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

    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    // To save space in the DP table, we use int as the return type.
    if (m > INT_MAX || n > INT_MAX) {
        errno = EDOM;
        return -1;
    }

    int *tab = malloc((m + 1) * 2 * sizeof(int));
    if (!tab) {
        return -1;
    }

    int *cur = tab, *prev = tab + m + 1;

    for (size_t i = 0; i <= m; i++) {
        cur[i] = i;
    }
    for (size_t j = 1; j <= n; j++) {
        int *t = cur;
        cur = prev;
        prev = t;

        cur[0] = j;

        for (size_t i = 1; i <= m; i++) {
            if (a[i - 1] == b[j - 1]) {
                cur[i] = prev[i - 1];
            }
            else {
                cur[i] = min3(cur[i - 1], prev[i], prev[i - 1]) + 1;
            }
        }
    }

    int r = cur[m];
    free(tab);
    return r;
}
