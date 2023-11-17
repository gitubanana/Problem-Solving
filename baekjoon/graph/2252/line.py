import sys
from collections import deque

def topological_sort(v_cnt, linked, indegree):
    ans = []
    q = deque()

    for v in range(1, v_cnt):
        if indegree[v] == 0:
            q.append(v)

    while q:
        cur = q.popleft()
        ans.append(cur)
        for next in linked[cur]:
            indegree[next] -= 1
            if indegree[next] == 0:
                q.append(next)

    for cur in ans:
        print(cur, end=' ')
    print()

if __name__ == '__main__':
    v_cnt, e_cnt = map(int, sys.stdin.readline().split(' '))
    v_cnt += 1

    linked = [[] for _ in range(v_cnt + 1)]
    indegree = [0 for _ in range(v_cnt + 1)]
    for _ in range(e_cnt):
        _from, to = map(int, sys.stdin.readline().split(' '))
        linked[_from].append(to)
        indegree[to] += 1

    topological_sort(v_cnt, linked, indegree)
