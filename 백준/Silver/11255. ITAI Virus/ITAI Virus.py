for _ in range(int(input())):
    vCnt, eCnt, _ = map(int, input().split())
    edges = [[] for _ in range(vCnt+1)]
    for _ in range(eCnt):
        a, b = map(int, input().split())
        edges[a].append(b)
        edges[b].append(a)
    
    foundVirus = [False for _ in range(vCnt+1)]
    for start in map(int, input().split()):
        foundVirus[start] = True
        for next in edges[start]:
            foundVirus[next] = True

    print(foundVirus.count(True))