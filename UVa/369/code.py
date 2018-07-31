#!/bin/python3

import sys

def fat(n):
    f = 1
    for i in range(2,n+1):
        f = f * i
    return f

def calc(n, m):
    return fat(n) / (fat(n-m) * fat(m))

if __name__ == '__main__':
    while True:
        i = list(map(lambda x: int(x), sys.stdin.readline().split()))
        if(len(i) != 2 or (i[0] == 0 and i[1] == 0)):
            break
        print("{} things taken {} at a time is {} exactly.".format(i[0],i[1], int(calc(i[0], i[1]) )) )