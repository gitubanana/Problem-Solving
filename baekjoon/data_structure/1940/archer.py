import sys

readline = lambda: sys.stdin.readline()
size = int(readline())
goal = int(readline())
arr = list(map(int, readline().split()))
arr.sort()

ans = 0
start, end = 0, size - 1
while start < end:
    sum_ = arr[start] + arr[end]
    if sum_ < goal:
        start += 1
    else:
        ans += sum_ == goal
        start += sum_ == goal
        end -= 1

print(ans)
