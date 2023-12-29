import sys

if __name__ == '__main__':
    start, end = map(int, sys.stdin.readline().split())
    cnt = [0 for _ in range(end + 1)]

    for i in range(start + 1, end + 1):
        last_half, is_not_doubled = divmod(i, 2)
        if (is_not_doubled
            or last_half < start):
            cnt[i] = cnt[i - 1] + 1
        else:
            cnt[i] = min(cnt[last_half], cnt[i - 1]) + 1
            
    print(cnt[end])
