import sys
from collections import deque

if __name__ == '__main__':
    readline = sys.stdin.readline
    size = int(readline())
    arr = list(map(int, readline().split()))
    o_arr = [-1 for _ in range(size)]
    temp = deque()

    temp.append(arr[size - 1])
    i = size - 2
    while i >= 0:
        while temp and temp[-1] <= arr[i]:
            temp.pop()
        if temp:
            o_arr[i] = temp[-1]
        temp.append(arr[i])
        i -= 1

    for NGE in o_arr:
        print(NGE, end=' ')
    print()

# 7
# 2
# 5
# 3
