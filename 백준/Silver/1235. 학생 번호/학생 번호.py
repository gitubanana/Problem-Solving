from sys import exit

def isIdentifiableByLast(compLen):
    global ids, idLen

    s = set()
    for id in ids:
        cutId = id[idLen-compLen:]
        if cutId in s:
            return False
        s.add(cutId)
    return True

size = int(input())
ids = []
for _ in range(size):
    ids.append(input())

idLen = len(ids[0])
for compLen in range(1, idLen):
    if isIdentifiableByLast(compLen):
        print(compLen)
        exit()

print(idLen)
