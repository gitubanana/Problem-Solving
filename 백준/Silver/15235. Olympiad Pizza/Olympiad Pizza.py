from collections import deque

size = int(input())
needCnt = list(map(int, input().split()))
fedTime = [0] * size
q = deque([i for i in range(size)])

time = 1
starvingCnt = size
while starvingCnt > 0:
    fresser = q.popleft()
    needCnt[fresser] -= 1
    if needCnt[fresser] > 0:
        q.append(fresser)
    else:
        starvingCnt -= 1
        fedTime[fresser] = time
    time += 1

print(*fedTime)
