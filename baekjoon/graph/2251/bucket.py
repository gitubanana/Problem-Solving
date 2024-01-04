import sys
from collections import deque

def pour(cur: list[int], from_: int, to: int) -> list[list[int]]:
    ret = []

    if cur[from_] == 0:
        return ret

    next = cur.copy()
    next[to] += next[from_]
    next[from_] = 0
    if next[to] > capacity[to]:
        next[from_] = next[to] - capacity[to]
        next[to] = capacity[to]

    ret.append(next)
    return ret

def make_visited_true(l: list[int]) -> None:
    global visited

    visited[l[0]][l[1]][l[2]] = True

def is_visited(l: list[int]) -> bool:
    return visited[l[0]][l[1]][l[2]]

def bfs() -> None:
    global ans, visited

    q = deque()
    start = [0, 0, capacity[2]]
    make_visited_true(start)
    q.append(start)
    while q:
        cur = q.pop()

        for from_ in range(SIZE):
            for i in range(1, SIZE):
                to = (from_ + i) % SIZE
                for next in pour(cur, from_, to):
                    if is_visited(next):
                        continue

                    make_visited_true(next)
                    if next[0] == 0:
                        ans.add(next[2])
                    q.append(next)

if __name__ == '__main__':
    SIZE = 3
    capacity = list(map(int, input().split()))
    visited = [[[False for _ in range(capacity[2] + 1)]
                for _ in range(capacity[1] + 1)]
                for _ in range(capacity[0] + 1)]
    ans = set()
    ans.add(capacity[2])

    bfs()

    for num in sorted(list(ans)):
        print(num, end=' ')
    print()
