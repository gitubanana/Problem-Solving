import sys

n = int(sys.stdin.readline())
ans = 0
start = end = _sum = 1
while start <= n and end <= n:
    if _sum < n:
        end += 1
        _sum += end
    else:
        if _sum == n:
            ans += 1
        _sum -= start
        start += 1
print(ans)
