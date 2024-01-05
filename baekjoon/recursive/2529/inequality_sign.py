import sys

def back_tracking(depth):
    global arr, min_, max_

    if depth == LIMIT:
        join = ''.join(arr)
        min_ = min(min_, join)
        max_ = max(max_, join)
        return

    prev_idx = int(arr[depth - 1])
    if signs[depth - 1] == '<':
        start = prev_idx + 1
        end = 10
    else:
        start = 0
        end = prev_idx

    for n in NUMBERS[start:end]:
        if n not in arr[:depth]:
            arr[depth] = n
            back_tracking(depth + 1)


if __name__ == '__main__':
    ZERO = 48
    NUMBERS = ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9')
    def readline(): return sys.stdin.readline()

    LIMIT = int(readline()) + 1
    signs = list(readline().strip().split())
    arr = ['0' for _ in range(LIMIT)]
    min_, max_ = '999999999', '0'
    all = []

    for n in NUMBERS:
        arr[0] = n
        back_tracking(1)

    print(max_, min_, sep='\n')
