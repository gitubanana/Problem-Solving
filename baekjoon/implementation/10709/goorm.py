import sys

def readline(): return sys.stdin.readline()

y_size, x_size = map(int, readline().split())
for y in range(y_size):
    goorm = -1
    line = readline()
    for x in range(x_size):
        if line[x] == 'c':
            goorm = x
        print('-1' if goorm == -1 else x - goorm, end=' ')
    print()
