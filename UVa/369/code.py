#!/bin/python3

import sys
values = [0] * 102
values[0] = 1
for i in range(1, 102):
    values[i] = values[i-1] * i

while True:
    i = list(map(lambda x: int(x), sys.stdin.readline().split()))
    if(len(i) != 2 or (i[0] == 0 and i[1] == 0)):
        break
    print("{} things taken {} at a time is {} exactly.".format(
        i[0], i[1], int(values[i[0]] / (values[i[0] - i[1]] * values[i[1]]))))