import sys

if __name__ == '__main__':
    splitIntoInt = lambda: map(int, sys.stdin.readline().split())
    size, period = splitIntoInt()
    arr = list(splitIntoInt())

    cur_sum = sum(arr[:period])
    cnt, max = 1, cur_sum
    for i in range(period, size):
        cur_sum += arr[i] - arr[i - period]
        if max < cur_sum:
            max, cnt = cur_sum, 1
        elif max == cur_sum:
            cnt += 1

    if max == 0:
        print("SAD")
    else:
        print(max, cnt, sep='\n')
