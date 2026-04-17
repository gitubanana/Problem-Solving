import sys

line = lambda: sys.stdin.readline()
line()
l = sorted(map(int, line().split()))
print(l[0]+l[1])