def possibleToSpell(word):
    global assets

    needs = dict()
    for ch in word:
        needs[ch] = needs.get(ch, 0) + 1

    for ch, cnt in needs.items():
        if assets.get(ch, 0) < cnt:
            return False

    return True


for _ in range(int(input())):
    assets = dict()
    for ch in input():
        assets[ch] = assets.get(ch, 0) + 1

    for _ in range(int(input())):
        print('YES' if possibleToSpell(input()) else 'NO')
