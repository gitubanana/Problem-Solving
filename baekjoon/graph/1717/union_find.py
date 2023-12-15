import sys

sys.setrecursionlimit(10**6 + 1)

def get_parent(x: int) -> int:
    global parents

    if parents[x] == x:
        return x
    parents[x] = get_parent(parents[x])
    return parents[x]

def union(x: int, y: int) -> None:
    global parents

    x_parent = get_parent(x)
    y_parent = get_parent(y)
    if x_parent > y_parent:
        parents[x_parent] = y_parent
    else:
        parents[y_parent] = x_parent

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    v_cnt, cmd_cnt = splitIntoInt()
    v_cnt += 1
    parents = [0 for _ in range(v_cnt)]
    for v in range(v_cnt):
        parents[v] = v

    while cmd_cnt:
        cmd, x, y = splitIntoInt()
        if cmd == 0:
            union(x, y)
        else:
            print("YES" if get_parent(x) == get_parent(y) else "NO")
        cmd_cnt -= 1
