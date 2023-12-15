import sys


def bellman_ford(START, v_cnt) -> int:
    global dist

    dist[START] = 0
    for _ in range(1, v_cnt):
        for from_, to, weight in edges:
            next_dist = dist[from_] + weight
            if dist[from_] != INF and dist[to] > next_dist:
                dist[to] = next_dist

    for from_, to, weight in edges:
        next_dist = dist[from_] + weight
        if dist[from_] != INF and dist[to] > next_dist:
            return NEGATIVE_CYCLE

    return True


if __name__ == '__main__':
    START = 1
    INF = 10**11
    CANNOT_GO = '-1'
    NEGATIVE_CYCLE = -1
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    v_cnt, e_cnt = splitIntoInt()
    v_cnt += 1
    edges = []
    dist = [INF for _ in range(v_cnt)]
    while e_cnt:
        edges.append(list(splitIntoInt()))
        e_cnt -= 1

    if bellman_ford(START, v_cnt - 1) == NEGATIVE_CYCLE:
        print(NEGATIVE_CYCLE)
    else:
        for v in range(2, v_cnt):
            print(CANNOT_GO if dist[v] == INF else dist[v])
