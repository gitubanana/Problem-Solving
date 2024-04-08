import sys


def merge_sort(left, right):
    global ans, arr, tmp

    if left >= right:
        return

    mid = (left + right) // 2
    merge_sort(left, mid)
    merge_sort(mid + 1, right)

    in_ = left
    l, r = left, mid + 1
    while l <= mid and r <= right:
        if arr[l] > arr[r]:
            ans += r - in_
            tmp[in_] = arr[r]
            r += 1
        else:
            tmp[in_] = arr[l]
            l += 1
        in_ += 1

    while r <= right:
        tmp[in_] = arr[r]
        r += 1
        in_ += 1

    while l <= mid:
        tmp[in_] = arr[l]
        l += 1
        in_ += 1

    for i in range(left, right + 1):
        arr[i] = tmp[i]


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    i = -1
    size = int(readline())
    arr = list(map(int, readline().split()))
    tmp = [0 for _ in range(size)]

    ans = 0
    merge_sort(0, size - 1)
    print(ans)
