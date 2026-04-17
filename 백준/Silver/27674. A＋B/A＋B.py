import sys

line = lambda: sys.stdin.readline().strip()

def listToInt(l):
    n = 0
    for i in l:
        n = n * 10 + (ord(i) - ord('0'))
    return n

for _ in range(int(line())):
    line()
    l = sorted(line(), reverse=True)
    print(listToInt(l[:-1]) + listToInt(l[-1:]))