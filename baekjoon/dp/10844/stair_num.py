import sys

if __name__ == '__main__':
    DIVISOR = 1000000000
    size = int(sys.stdin.readline())
    dp = [[0 for _ in range(10)] for _ in range(size + 1)]

    for i in range(1, 10):
        dp[1][i] = 1

    for s in range(2, size + 1):
        dp[s][0] = dp[s - 1][1]
        for n in range(1, 9):
            dp[s][n] = dp[s - 1][n - 1] + dp[s - 1][n + 1]
            dp[s][n] %= DIVISOR
        dp[s][9] = dp[s - 1][8] % DIVISOR

    print(sum(dp[size]) % DIVISOR)
