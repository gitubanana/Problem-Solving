import sys
import math

if __name__ == '__main__':
    splitIntoInt = lambda: map(int, sys.stdin.readline().split())
    size, divisor = splitIntoInt()
    arr = list(splitIntoInt())
    cnt = [0 for _ in range(divisor)]

    arr[0] %= divisor
    cnt[arr[0]] = 1
    for i in range(1, size):
        arr[i] += (arr[i - 1] % divisor)
        arr[i] %= divisor
        cnt[arr[i]] += 1

    ans = cnt[0]
    for i in range(divisor):
        ans += math.comb(cnt[i], 2)

    print(ans)
