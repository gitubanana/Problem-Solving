num = lambda: int(input())
ans = 0
for _ in range(num()):
    ans += num()
print(ans)