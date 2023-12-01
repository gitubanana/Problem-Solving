import sys

if __name__ == '__main__':
    readline = lambda: sys.stdin.readline()
    size = int(readline())
    arr = list(map(int, readline().split()))
    arr.sort()

    ans = 0
    for i in range(size):
        goal = arr[i]
        start, end = 0, size - 1
        while start < end:
            cur_sum = arr[start] + arr[end]
            if cur_sum < goal:
                start += 1
            elif cur_sum > goal:
                end -= 1
            else:
                if start == i:
                    start += 1
                elif end == i:
                    end -= 1
                else:
                    ans += 1
                    break

    print(ans)