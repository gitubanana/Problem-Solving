import sys

if __name__ == '__main__':
    n = int(sys.stdin.readline()) + 1
    dp = [1 for _ in range(n)]

    for i in range(3, n):
        dp[i] = dp[i - 1] + dp[i - 2]

    print(dp[n - 1])
