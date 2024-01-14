import sys

def dfs(cur):
    global visited

    ret = False
    blocked_cnt = 0
    visited[cur[Y]][cur[X]] = True
    for i in range(4):
        next = (cur[Y] + DY[i], cur[X] + DX[i])
        if (not (0 <= next[Y] < y_size)
            or not (0 <= next[X] < x_size)
            or town[next[Y]][next[X]] == BLOCKED):
            blocked_cnt += 1
            continue

        if not visited[next[Y]][next[X]]:
            ret |= dfs(next)

    return ret or blocked_cnt >= 3

def readline(): return sys.stdin.readline()

ROAD = '.'
BLOCKED = 'X'
Y, X = 0, 1
DY, DX = (1, 0, -1, 0), (0, 1, 0, -1)
y_size, x_size = map(int, readline().split())
town = [readline() for _ in range(y_size)]
ans = False
visited = [[False for _ in range(x_size)] for _ in range(y_size)]

for y in range(y_size):
    for x in range(x_size):
        if (town[y][x] == ROAD
            and not visited[y][x]):
            ans |= dfs((y, x))

print(int(ans))
