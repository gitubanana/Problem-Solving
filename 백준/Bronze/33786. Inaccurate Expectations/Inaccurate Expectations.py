import sys
sys.setrecursionlimit(10000)

def g(n):
    if n == 0:
        return 0
    return n + g(n-1)*n

print(g(int(input())))
