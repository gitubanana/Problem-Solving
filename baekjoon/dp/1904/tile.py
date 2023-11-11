import sys

n = int(sys.stdin.readline()) + 1
dp = [0 for _ in range(n)]
dp[0] = 1
dp[1] = 1
for i in range(2, n):
    dp[i] = (dp[i - 1] + dp[i - 2]) % 15746

print(dp[n - 1])
