import sys
from heapq import heappush, heappop

class Pos:
    def __init__(self, y, x, w) -> None:
        self.y = y
        self.x = x
        self.w = w

    def __gt__(self, other) -> bool:
        return self.w > other.w

def dijkstra(map_, size) -> int:
    pq = []

    dist[0][0] = map_[0][0]
    heappush(pq, Pos(0, 0, map_[0][0]))
    while pq:
        cur = heappop(pq)
        for dy, dx in zip(DY, DX):
            next_y, next_x = cur.y + dy, cur.x + dx
            if not (0 <= next_y < size
                and 0 <= next_x < size):
                continue
            next_dist = cur.w + map_[next_y][next_x]
            if dist[next_y][next_x] > next_dist:
                dist[next_y][next_x] = next_dist
                heappush(pq, Pos(next_y, next_x, next_dist))

    return dist[size - 1][size - 1]

if __name__ == '__main__':
    DY = [-1, 1, 0, 0]
    DX = [0, 0, -1, 1]
    INF = 10**4
    problem_id = 1
    readline = lambda: sys.stdin.readline()
    splitIntoInt = lambda: map(int, readline().split())
    while True:
        size = int(readline())
        if size == 0:
            break
    
        map_ = [list(splitIntoInt()) for _ in range(size)]
        dist = [[INF for _ in range(size)] for _ in range(size)]
    
        print(f'Problem {problem_id}: {dijkstra(map_, size)}')
        problem_id += 1
