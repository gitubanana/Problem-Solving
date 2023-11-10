import sys

def w(a, b, c):
    if a <= 0 or b <= 0 or c <= 0:
        return 1

    if a > 20 or b > 20 or c > 20:
        return dp[20][20][20]

    return dp[a][b][c]

def init_dp():
    for z in range(1, max):
        for y in range(1, max):
            for x in range(1, max):
                if z < y < x:
                    dp[z][y][x] = dp[z][y][x - 1] + dp[z][y - 1][x - 1] - dp[z][y - 1][x]
                else:
                    dp[z][y][x] = (dp[z - 1][y][x] + dp[z - 1][y - 1][x]
                                    + dp[z - 1][y][x - 1] - dp[z - 1][y - 1][x - 1])

max = 21
stop = -1
dp = [[[1 for _ in range(max)] for _ in range(max)] for _ in range(max)]
init_dp()
while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == stop and b == stop and c == stop:
        break
    print(f'w({a}, {b}, {c}) = {w(a, b, c)}')
