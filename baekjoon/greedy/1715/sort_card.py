import sys
from heapq import heappush, heappop

if __name__ == '__main__':
    inputToInt = lambda: int(sys.stdin.readline())
    size = inputToInt()
    heap = []

    for _ in range(size):
        heappush(heap, inputToInt())

    cmp_cnt = 0
    if size >= 2:
        while heap:
            plus = heappop(heap)
            if heap:
                plus += heappop(heap)
            if heap:
                heappush(heap, plus)
            cmp_cnt += plus

    print(cmp_cnt)
