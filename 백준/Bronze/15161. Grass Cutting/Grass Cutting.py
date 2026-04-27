SIZE = 10
cutXs = [0 for _ in range(SIZE)]
cutYs = [0 for _ in range(SIZE)]
end = int(input())+1
for t in range(1, end):
    arr = list(map(int, input().split()))
    cutYs[arr[0]-1] = cutYs[arr[1]-1] = cutYs[arr[2]-1] = t
    cutXs[arr[3]-1] = cutXs[arr[4]-1] = cutXs[arr[5]-1] = t

for y in range(SIZE):
    for x in range(SIZE):
        latest = max(cutXs[x], cutYs[y])
        print(end-latest, end=' ')
    print()
