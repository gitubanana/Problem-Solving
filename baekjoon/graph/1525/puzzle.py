import sys
from collections import deque

SIZE = 3
END = 123456789

def bfs(start: int) -> int:
    if start == END:
        return 0

    dy = (1, -1, 0, 0)
    dx = (0, 0, 1, -1)

    cnt = dict()
    q = deque()

    cnt[start] = 0
    q.append(start)
    while q:
        cur_int = q.popleft()
        cur = str(cur_int)
        curEmptyIdx = cur.find('9')
        cur_y = curEmptyIdx // 3
        cur_x = curEmptyIdx % 3

        for i in range(4):
            next_y = cur_y + dy[i]
            next_x = cur_x + dx[i]

            if (not 0 <= next_y < SIZE or
                not 0 <= next_x < SIZE):
                continue

            next = list(cur)
            nextEmptyIdx = next_y * 3 + next_x
            next[nextEmptyIdx], next[curEmptyIdx] = next[curEmptyIdx], next[nextEmptyIdx]

            next_int = int("".join(next))
            if next_int in cnt:
                continue

            cnt[next_int] = cnt[cur_int] + 1
            if next_int == END:
                return cnt[next_int]

            q.append(next_int)

    return -1

if __name__ == '__main__':
    start = 0
    for _ in range(SIZE):
        for n in sys.stdin.readline().strip().split(' '):
            if n == '0':
                n = '9'
            start = start * 10 + int(n)

    print(bfs(start))
