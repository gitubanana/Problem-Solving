import sys

if __name__ == '__main__':
    splitIntoInt = lambda: map(int, sys.stdin.readline().split())
    size, goal = splitIntoInt()
    arr = list(splitIntoInt())

    start, end = 0, 1
    cur_sum, cnt = arr[0], 0
    while True:
        if cur_sum < goal:
            if end < size:
                cur_sum += arr[end]
                end += 1
            else:
                break
        elif cur_sum > goal:
            cur_sum -= arr[start]
            start += 1
        else:
            cnt += 1
            cur_sum -= arr[start]
            start += 1

    print(cnt)
