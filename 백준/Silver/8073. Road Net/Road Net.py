size = int(input())
dists = [list(map(int, input().split())) for _ in range(size)]
isNeighbor = [[True for _ in range(size)] for _ in range(size)]

for mid in range(size):
    for from_ in range(size):
        if mid == from_:
            continue

        for to in range(size):
            if mid == to:
                continue

            if dists[from_][to] >= dists[from_][mid] + dists[mid][to]:
                isNeighbor[from_][to] = False

for from_ in range(size):
    for to in range(from_+1, size):
        if isNeighbor[from_][to]:
            print(from_+1, to+1)
