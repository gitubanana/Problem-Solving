import sys

def findCombination(cnt):
    pairCnt = cnt.count(2)
    tripleCnt = cnt.count(3)
    tikiCnt = cnt.count(4)

    if pairCnt == 1 and tripleCnt == 1:
        return 'full house'

    if pairCnt == 1 and tikiCnt == 1:
        return 'tiki pair'

    if tikiCnt == 1:
        return 'tiki'

    if tripleCnt == 2:
        return 'two triples'

    if tripleCnt == 1:
        return 'one triple'

    if pairCnt == 3:
        return 'three pairs'

    if pairCnt == 2:
        return 'two pairs'

    if pairCnt == 1:
        return 'one pair'

    return 'single'

line = lambda: sys.stdin.readline().strip()
for _ in range(int(line())):
    cnt = [0] * 14
    for card in map(int, line().split()):
        cnt[card] += 1

    print(findCombination(cnt))
