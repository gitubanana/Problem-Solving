import sys

readline = lambda: sys.stdin.readline()

for _ in range(3):
    size = int(readline())
    s = 0
    for _ in range(size):
        s += int(readline())
    if s == 0:
        print('0')
    elif s > 0:
        print('+')
    else:
        print('-')
