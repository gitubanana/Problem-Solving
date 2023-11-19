import sys

n = int(sys.stdin.readline())
dp = [0 for _ in range(n + 1)]
dp[0] = 4
dp[1] = 6
for i in range(2, n):
    dp[i] = dp[i - 1] + dp[i - 2]

print(dp[n - 1])
