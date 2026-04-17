import sys

sys.setrecursionlimit(2001)

def back_tracking(cur_v, right_before, depth=0) -> bool:
    global links, visited

    if depth == DEPTH_LIMIT:
        return True

    for next in links[cur_v]:
        if (next != right_before
            and visited[next] == False):
            visited[next] = True
            if back_tracking(next, cur_v, depth + 1):
                return True
            visited[next] = False

    return False

DEPTH_LIMIT = 4
splitIntoInt = lambda: map(int, sys.stdin.readline().split())
v_cnt, e_cnt = splitIntoInt()
links = [[] for _ in range(v_cnt)]
visited = [False for _ in range(v_cnt)]
while e_cnt:
    from_, to = splitIntoInt()
    links[from_].append(to)
    links[to].append(from_)
    e_cnt -= 1

answer = "0"
for v in range(v_cnt):
    visited[v] = True
    if back_tracking(v, -1):
        answer = "1"
        break
    visited[v] = False

print(answer)
