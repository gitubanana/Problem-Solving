import sys

sys.setrecursionlimit(20001)

def dfs(cur: int, color: int) -> bool:
    global colors

    colors[cur] = color
    for next in links[cur]:
        if colors[next] == EMPTY:
            if not dfs(next, int(not color)):
                return False
        elif color == colors[next]:
            return False
    return True

if __name__ == '__main__':
    readline = lambda: sys.stdin.readline()
    splitIntoInt = lambda: map(int, readline().split())
    EMPTY, BLACK, WHITE = -1, 0, 1

    test_cnt = int(readline())
    while test_cnt:
        v_cnt, e_cnt = splitIntoInt()
        v_cnt += 1
        links = [[] for _ in range(v_cnt)]
        colors = [EMPTY for _ in range(v_cnt)]

        while e_cnt:
            from_, to = splitIntoInt()
            links[from_].append(to)
            links[to].append(from_)
            e_cnt -= 1

        print_msg = "YES"
        for v in range(1, v_cnt):
            if (colors[v] == EMPTY
                and not dfs(v, BLACK)):
                print_msg = "NO"
                break
        print(print_msg)

        test_cnt -= 1
