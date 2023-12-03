import sys

def get_sum(start, end):
    if start == 0:
        return sums[end]
    return sums[end] - sums[start - 1]

if __name__ == '__main__':
    splitIntoInt = lambda: map(int, sys.stdin.readline().split())
    size, period = splitIntoInt()
    arr = list(splitIntoInt())
    sums = [0 for _ in range(size)]

    sums[0] = arr[0]
    for i in range(1, size):
        sums[i] = sums[i - 1] + arr[i]

    cnt, max = 0, 0
    start, end = 0, period - 1
    while end < size:
        cur_sum = get_sum(start, end)
        if max < cur_sum:
            max, cnt = cur_sum, 1
        elif max == cur_sum:
            cnt += 1
        start += 1
        end += 1

    if max == 0:
        print("SAD")
    else:
        print(max, cnt, sep='\n')
