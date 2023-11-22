import sys
from collections import deque

def bfs(links, v_cnt, start):
    for i in range(1, v_cnt):
        links[i].sort()

    depth = [-1 for _ in range(v_cnt)]
    order = [0 for _ in range(v_cnt)]
    cur_order = 2

    q = deque()
    q.append(start)
    depth[start] = 0
    order[start] = 1
    while q:
        cur = q.popleft()
        for next in links[cur]:
            if order[next] != 0:
                continue
            depth[next] = depth[cur] + 1
            order[next] = cur_order
            cur_order += 1
            q.append(next)
    
    ans = 0
    for i in range(1, v_cnt):
        ans += (order[i] * depth[i])
    print(ans)

if __name__ == '__main__':
    v_cnt, e_cnt, start = map(int, sys.stdin.readline().split(' '))
    v_cnt += 1
    links = [[] for _ in range(v_cnt)]

    while e_cnt:
        _from, to = map(int, sys.stdin.readline().split(' '))
        links[_from].append(to)
        links[to].append(_from)
        e_cnt -= 1

    bfs(links, v_cnt, start)
