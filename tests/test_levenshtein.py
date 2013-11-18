from __future__ import division

from nose.tools import assert_equal, assert_raises, assert_true

from leven import levenshtein
import numbers
from six import b


S1 = b("kitten")
S2 = b("sitting")

U1 = S1.decode("utf-8")
U2 = S2.decode("utf-8")


def test_distance():
    assert_equal(levenshtein(S1, S2), 3)
    assert_equal(levenshtein(U1, U2), 3)
    assert_equal(levenshtein(S2, S1), 3)
    assert_equal(levenshtein(U2, U1), 3)

    for x in (S1, S2, U1, U2):
        assert_equal(levenshtein(x, x), 0)


def test_normalize():
    assert_true(isinstance(levenshtein(S2, S1), numbers.Integral))
    assert_equal(levenshtein("", "", normalize=True), 0)
    assert_equal(levenshtein(S1, S2, normalize=True), 3 / 7)


def test_types():
    assert_raises(TypeError, levenshtein, S1, U2)
    assert_raises(TypeError, levenshtein, U1, S2)
