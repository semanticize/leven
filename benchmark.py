import sys
from timeit import timeit

from leven import levenshtein

n_runs = 30

with open("/usr/share/dict/words") as f:
    strs = [ln.strip() for ln in f]
print("Running %d times on %d reference strings" % (n_runs, len(strs)))

arg = sys.argv[1]
t = timeit(stmt='for s in strs: levenshtein(arg, s)',
           setup='from __main__ import arg, levenshtein, strs',
           number=n_runs)
print("%.3f seconds" % t)
