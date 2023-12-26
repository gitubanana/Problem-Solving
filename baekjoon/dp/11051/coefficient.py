import sys

sys.setrecursionlimit(1001)


def get_comb(N, R):
    global memory

    if R == 1:
        return N

    if R == 0 or N == R:
        return 1

    key = (N, R)

    if key in memory:
        return memory[key]

    memory[key] = (((get_comb(N - 1, R - 1) % DIVISOR)
                    + (get_comb(N - 1, R) % DIVISOR)) % DIVISOR)
    return memory[key]


if __name__ == '__main__':
    DIVISOR = 10007
    N, R = map(int, sys.stdin.readline().split())
    memory = dict()

    print(get_comb(N, R))
