sortedHeights = lambda: sorted(list(map(int, input().split())))

ans = 0
for cmp in zip(sortedHeights(), sortedHeights()):
    if cmp[0] > cmp[1]:
        ans += 1

print(ans)
