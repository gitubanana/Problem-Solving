import sys


def can_go(cur, end, visited):

    if cur == end:
        return True

    visited[cur] = True
    for next, _ in links[cur]:
        if (not visited[next]
                and can_go(next, end, visited)):
            return True
    return False


def bellman_ford(start, end):
    global dist

    dist[start] = earnings[start]
    for _ in range(v_cnt):
        for from_ in range(v_cnt):
            for to, weight in links[from_]:
                next_dist = dist[from_] - weight + earnings[to]
                if dist[from_] != -INF and dist[to] < next_dist:
                    dist[to] = next_dist

    for from_ in range(v_cnt):
        for to, weight in links[from_]:
            next_dist = dist[from_] - weight + earnings[to]
            if dist[from_] != -INF and dist[to] < next_dist:
                visited = [False for _ in range(v_cnt)]
                if can_go(to, end, visited):
                    return NEGATIVE_CYCLE

    return True


if __name__ == '__main__':
    INF = 1e9
    NEGATIVE_CYCLE = False
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    v_cnt, start, end, e_cnt = splitIntoInt()
    links = [[] for _ in range(v_cnt)]
    while e_cnt:
        from_, to, weight = splitIntoInt()
        links[from_].append((to, weight))
        e_cnt -= 1
    earnings = list(splitIntoInt())

    dist = [-INF for _ in range(v_cnt)]
    bf_ret = bellman_ford(start, end)
    if dist[end] == -INF:
        print('gg')
    elif bf_ret == NEGATIVE_CYCLE:
        print('Gee')
    else:
        print(dist[end])
