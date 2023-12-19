import sys
from math import sqrt

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    start, end = splitIntoInt()
    end_sqrt = int(sqrt(end))

    primes = []
    is_prime = [False, False] + [True] * (end_sqrt - 1)

    for i in range(2, end_sqrt + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(2 * i, end_sqrt + 1, i):
                is_prime[j] = False

    cnt = 0
    cur = 2
    for cur in primes:
        tmp = cur * cur
        while tmp <= end:
            cnt += (start <= tmp)
            tmp *= cur

    print(cnt)
