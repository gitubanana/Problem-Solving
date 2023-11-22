import sys
from collections import deque

def bfs(links, v_cnt, start):
    depth = [-1 for _ in range(v_cnt)]

    q = deque()
    q.append(start)
    depth[start] = 0
    while q:
        cur = q.popleft()
        for next in links[cur]:
            if depth[next] != -1:
                continue
            depth[next] = depth[cur] + 1
            q.append(next)
    
    for i in range(1, v_cnt):
        print(depth[i])

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
