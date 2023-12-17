import sys

sys.setrecursionlimit(10**5 + 1)

def dfs(cur: int) -> int:
    global visited

    ret = 0
    visited[cur] = True
    for next in edges[cur]:
        if visited[next]:
            continue
        ret += dfs(next) + 1

    return ret

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    v_cnt, e_cnt = splitIntoInt()
    edges = [[] for _ in range(v_cnt + 1)]
    visited = [False for _ in range(v_cnt + 1)]
    while e_cnt:
        to, from_ = splitIntoInt()
        edges[from_].append(to)
        e_cnt -= 1
    start = int(readline())

    print(dfs(start))

