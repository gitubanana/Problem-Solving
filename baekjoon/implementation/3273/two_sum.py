import sys

if __name__ == '__main__':
    readline = lambda: sys.stdin.readline()
    size = int(readline())
    arr = list(map(int, readline().split()))
    goal = int(readline())
    
    arr.sort()
    
    cnt = 0
    start, end = 0, size - 1
    while start < end:
        sum_ = arr[start] + arr[end]
        if sum_ == goal:
            cnt += 1
            start += 1
        elif sum_ > goal:
            end -= 1
        else:
            start += 1
    
    print(cnt)
