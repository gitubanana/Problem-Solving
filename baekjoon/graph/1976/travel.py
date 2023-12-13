import sys

def get_parent(x: int) -> int:
    global parents

    if x == parents[x]:
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
    readline = lambda: sys.stdin.readline()
    v_cnt = int(readline()) + 1
    city_cnt = int(readline())
    parents = [0 for _ in range(v_cnt)]

    for v in range(1, v_cnt):
        parents[v] = v

    for from_ in range(1, v_cnt):
        to = 1
        for is_linked in map(int, readline().split()):
            if is_linked:
                union(from_, to)
            to += 1

    plan = list(map(int, readline().split()))
    p = min(plan)
    answer = "YES"
    for cur in plan:
        if get_parent(cur) != p:
            answer = "NO"
            break
    print(answer)
