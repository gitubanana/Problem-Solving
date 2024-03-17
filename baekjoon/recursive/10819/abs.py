import sys

def back_tracking(prevNum, depth=1, curAbs=0):
    global ans, visited

    if depth == limit:
        ans = max(ans, curAbs)
        return

    for i in range(limit):
        if visited[i]:
            continue
        visited[i] = True
        back_tracking(arr[i], depth + 1, curAbs + abs(prevNum - arr[i]))
        visited[i] = False

readline = lambda: sys.stdin.readline()
splitIntoInt = lambda: map(int, readline().split())
limit = int(readline())
arr = list(splitIntoInt())
visited = [False] * limit
ans = 0

for i in range(limit):
    visited[i] = True
    back_tracking(arr[i])
    visited[i] = False

print(ans)
