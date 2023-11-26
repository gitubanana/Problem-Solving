import sys

if __name__ == '__main__':
    readline = sys.stdin.readline
    size, test_cnt = map(int, readline().split(' '))

    table = []
    for y in range(size):
        table.append(list(map(int, readline().split(' '))))

    size += 1
    dp = [[0] * size for _ in range(size)]

    for y in range(1, size):
        for x in range(1, size):
            dp[y][x] = (dp[y][x - 1] + dp[y - 1][x]
                        - dp[y - 1][x - 1] + table[y - 1][x - 1])

    while test_cnt:
        y1, x1, y2, x2 = map(int, readline().split(' '))
        print(dp[y2][x2] - dp[y2][x1 - 1] - dp[y1 - 1][x2] + dp[y1 - 1][x1 - 1])
        test_cnt -= 1
