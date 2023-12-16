import sys

def distance(cur, dest) -> bool:
    global dist

    if cur == dest:
        return True

    visited[cur] = True
    for next, w in tree[cur]:
        if not visited[next]:
            dist[next] = min(dist[next], dist[cur] + w)
            if distance(next, dest):
                return True
    return False

INF = 10 ** 6
readline = lambda: sys.stdin.readline()
splitIntoInt = lambda: map(int, readline().split())
v_cnt, test_cnt = splitIntoInt()
tree = [[] for _ in range(v_cnt + 1)]
for _ in range(1, v_cnt):
    from_, to, weight = splitIntoInt()
    tree[from_].append([to, weight])
    tree[to].append([from_, weight])

dist = [INF for _ in range(v_cnt + 1)]
visited = [False for _ in range(v_cnt + 1)]
while test_cnt:
    from_, to = splitIntoInt()
    dist[from_] = 0
    distance(from_, to)
    print(dist[to])
    test_cnt -= 1
    if test_cnt:
        for i in range(1, v_cnt + 1):
            dist[i] = INF
            visited[i] = False
