len = int(input())
cur, next = input(), input()

ans = 0
for i in range(len):
    ans += min(
        abs(ord(cur[i]) - ord(next[i])),
        26 - abs(ord(cur[i]) - ord(next[i]))
    )

print(ans)
