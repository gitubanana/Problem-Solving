import sys


def get_next_room(cur_x: int) -> list[int]:
    return [cur_x, cur_x + 1]


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    size = int(readline())
    triangle = [list(splitIntoInt()) for _ in range(size)]
    dp = [[0] * i for i in range(1, size + 1)]

    dp[0][0] = triangle[0][0]
    for cur_y in range(size - 1):
        next_y = cur_y + 1
        for cur_x in range(cur_y + 1):
            for next_x in get_next_room(cur_x):
                dp[next_y][next_x] = max(dp[next_y][next_x],
                                         dp[cur_y][cur_x] + triangle[next_y][next_x])

    print(max(dp[size - 1]))
