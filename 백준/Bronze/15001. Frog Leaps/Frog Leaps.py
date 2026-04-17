stopCnt = int(input())
prev = int(input())

ans = 0
for _ in range(1, stopCnt):
    cur = int(input())
    ans += (cur - prev) ** 2
    prev = cur

print(ans)
