from sys import stdin
from itertools import combinations

inp = stdin.readline()
while inp:
    N, K = map(int, inp.split())

    means = combinations(map(int, stdin.readline().split()), 3)
    means = [sum(m)/3 for m in means]
    means.sort(reverse=True)
    print(round(means[K-1], 1))
    inp = stdin.readline()