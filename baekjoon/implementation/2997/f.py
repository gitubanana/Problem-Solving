import sys

def get_fourth_num(start, stop, step):

    diff = arr[start + step] - arr[start]
    i = start + step + step
    while i != stop:
        if arr[i] != arr[i - step] + diff:
            fourth_num = arr[i - step] + diff
            break
        i += step

    if i == stop:
        return arr[i - step] + diff
    elif fourth_num + diff == arr[i]:
        return fourth_num
    return None



if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    arr = list(splitIntoInt())
    arr.sort()

    print(get_fourth_num(0, 3, 1) or get_fourth_num(2, -1, -1))
