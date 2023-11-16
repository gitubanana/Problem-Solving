import sys

sys.setrecursionlimit(10**6)

def dfs(cur, depth):
    ans[cur] = depth

    for next in linked[cur]:
        if ans[next] == -1:
            dfs(next, depth + 1)

def print_ans(v_cnt, start):
    for i in range(1, v_cnt):
        linked[i].sort(reverse = True)

    dfs(start, 0)

    for i in range(1, v_cnt):
        print(ans[i])

v_cnt, e_cnt, start = map(int, sys.stdin.readline().split(' '))
v_cnt += 1
linked = [[] for _ in range(v_cnt)]
ans = [-1] * (v_cnt)
while e_cnt:
    _from, to = map(int, sys.stdin.readline().split(' '))
    linked[_from].append(to)
    linked[to].append(_from)
    e_cnt -= 1
print_ans(v_cnt, start)
