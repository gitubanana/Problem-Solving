import math

arr = list(map(int, input().split()))

ans = '3'
maxNum = max(arr)
arr.remove(maxNum)
if maxNum == sum(arr):
    ans = '1'
elif maxNum == math.prod(arr):
    ans = '2'

print(ans)
