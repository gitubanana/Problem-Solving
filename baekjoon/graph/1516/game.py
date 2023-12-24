import sys


def dfs(cur):
    global visited, orders

    visited[cur] = True
    for next in links[cur]:
        if not visited[next]:
            dfs(next)

    orders.append(cur)


def topological_sort():
    for v in range(1, v_cnt):
        if not visited[v]:
            dfs(v)


def get_times(cur):
    global visited, time

    if visited[cur]:
        return time[cur]

    ret = 0
    visited[cur] = True
    for next in links[cur]:
        ret = max(ret, get_times(next))
    return ret


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    v_cnt = int(readline()) + 1
    time = [0 for _ in range(v_cnt)]
    links = [[] for _ in range(v_cnt)]
    for from_ in range(1, v_cnt):
        arr = list(splitIntoInt())
        time[from_] = arr[0]

        i = 1
        while arr[i] != -1:
            links[from_].append(arr[i])
            i += 1

    orders = []
    visited = [False for _ in range(v_cnt)]
    topological_sort()

    visited = [False for _ in range(v_cnt)]
    for v in orders:
        time[v] += get_times(v)

    for v in range(1, v_cnt):
        print(time[v])
