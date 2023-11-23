import sys

if __name__ == '__main__':
    RGB = [0, 1, 2]
    n = int(sys.stdin.readline())
    dp = [[] for _ in range(n)]
    for i in range(n):
        dp[i] = list(map(int, sys.stdin.readline().split(' ')))

    for i in range(1, n):
        for color in RGB:
            one, two = (color + 1) % 3, (color + 2) % 3
            dp[i][color] += min(dp[i - 1][one], dp[i - 1][two])
    
    print(min(dp[n - 1]))
