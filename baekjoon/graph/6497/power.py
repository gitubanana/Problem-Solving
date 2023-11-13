import sys

class t_edge():
    def __init__(self, _from, to, weight):
        self._from = _from
        self.to = to
        self.weight = weight

def find(v):
    if (parent[v] == v):
        return (v)
    parent[v] = find(parent[v])
    return parent[v]

def _union(x, y):
    x_parent = find(x)
    y_parent = find(y)

    if x_parent < y_parent:
        parent[y_parent] = x_parent
    else:
        parent[x_parent] = y_parent

def min_weight(v_cnt):
    total_weight = 0

    for i in range(0, v_cnt):
        parent[i] = i

    v_cnt -= 1
    for cur_edge in edges:
        if find(cur_edge._from) != find(cur_edge.to):
            _union(cur_edge._from, cur_edge.to)
            v_cnt -= 1
            total_weight += cur_edge.weight
        if v_cnt == 0:
            break

    return (total_weight)

if __name__ == '__main__':
    while True:
        v_cnt, e_cnt = map(int, sys.stdin.readline().split())
        if v_cnt == 0 and e_cnt == 0:
            break
        sum = 0
        edges = []
        for _ in range(e_cnt):
            _from, to, weight = map(int, sys.stdin.readline().split())
            sum += weight
            edges.append(t_edge(_from, to, weight))
        parent = [0 for _ in range(v_cnt)]
        edges.sort(key = lambda x:x.weight)
        print(sum - min_weight(v_cnt))
