import sys

sys.setrecursionlimit(10**5 + 1)

depth = []
turn = []
links = []
cur_order = 2

def dfs(cur):
    global cur_order

    for next in links[cur]:
        if turn[next] == 0:
            turn[next] = cur_order
            cur_order += 1
            depth[next] = depth[cur] + 1
            dfs(next)

if __name__ == '__main__':
    split_input = lambda: sys.stdin.readline().split(' ')
    v_cnt, e_cnt, start = map(int, split_input())
    v_cnt += 1
    links = [[] for _ in range(v_cnt)]

    while e_cnt:
        _from, to = map(int, split_input())
        links[_from].append(to)
        links[to].append(_from)
        e_cnt -= 1

    for i in range(1, v_cnt):
        links[i].sort()

    depth = [-1 for _ in range(v_cnt)]
    turn = [0 for _ in range(v_cnt)]
    turn[start] = 1
    depth[start] = 0
    dfs(start)

    ans = 0
    for i in range(1, v_cnt):
        ans += (turn[i] * depth[i])

    print(ans)
