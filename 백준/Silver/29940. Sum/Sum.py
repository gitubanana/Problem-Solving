size, goal = map(int, input().split())
cnt = dict()

for _ in range(size):
    n = int(input())
    if goal < n:
        continue

    cnt[n] = cnt.get(n, 0) + 1
    cnt[goal - n] = cnt.get(goal - n, 0) + 1

ans = 0
for v in cnt.values():
    if v == 2:
        ans += 1

print(ans // 2)
