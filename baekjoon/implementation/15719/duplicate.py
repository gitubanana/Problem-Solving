import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    N = int(readline())
    origin_sum = N*(N - 1) // 2

    num = ''
    for ch in sys.stdin.read():
        if ch.isdigit():
            num += ch
        elif ch in (' ', '\n'):
            origin_sum -= int(num)
            num = ''

    print(-origin_sum)
