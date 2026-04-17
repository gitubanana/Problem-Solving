import sys
import math

line = lambda: sys.stdin.readline().strip()
while True:
    size = int(line())
    if size == 0:
        break

    deck = list([line() for _ in range(size)])
    top = 0
    half = math.ceil(size / 2)
    bottom = half
    while top < half or bottom < size:
        if top < half:
            print(deck[top])
            top = top + 1
        if bottom < size:
            print(deck[bottom])
            bottom = bottom + 1
