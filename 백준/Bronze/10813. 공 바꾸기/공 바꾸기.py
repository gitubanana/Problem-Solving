size, swapCnt = map(int, input().split())
arr = [str(i) for i in range(size+1)]

for _ in range(swapCnt):
    L, R = map(int, input().split())
    arr[L], arr[R] = arr[R], arr[L]

arr.pop(0)
print(" ".join(arr))
