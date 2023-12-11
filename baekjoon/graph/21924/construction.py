import sys


class Edge:
    def __init__(self, from_, to, weight) -> None:
        self.from_ = from_
        self.to = to
        self.weight = weight

    def __gt__(self, other) -> bool:
        return self.weight > other.weight


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


def get_min_weight() -> int:
    min_weight = 0
    rest_cnt = v_cnt

    for cur in edges:
        if get_parent(cur.from_) != get_parent(cur.to):
            min_weight += cur.weight
            union(cur.from_, cur.to)
            rest_cnt -= 1
        if rest_cnt == 0:
            break

    for v in range(1, v_cnt + 1):
        if get_parent(v) != 1:
            return -1
    return min_weight


if __name__ == '__main__':
    def splitIntoInt(): return map(int, sys.stdin.readline().split())
    v_cnt, e_cnt = splitIntoInt()
    total = 0
    edges = []

    while e_cnt:
        edges.append(Edge(*splitIntoInt()))
        total += edges[-1].weight
        e_cnt -= 1

    edges.sort()
    parents = [0 for _ in range(v_cnt + 1)]
    for v in range(1, v_cnt + 1):
        parents[v] = v

    min_weight = get_min_weight()
    if min_weight == -1:
        print("-1")
    else:
        print(total - min_weight)
