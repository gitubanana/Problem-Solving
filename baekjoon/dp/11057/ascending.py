import sys

if __name__ == '__main__':
    DIVISOR = 10007
    size = int(sys.stdin.readline())

    dp = [[1 for _ in range(10)] for _ in range(size)]
    for s in range(1, size):
        for n in range(10):
            dp[s][n] = sum(dp[s - 1][n:]) % DIVISOR

    print(sum(dp[size - 1]) % DIVISOR)
