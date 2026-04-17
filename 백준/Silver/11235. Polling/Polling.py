cntByName = dict()
for _ in range(int(input())):
    name = input()
    cntByName[name] = cntByName.get(name, 0) + 1

candidates = []
maxCnt = max(cntByName.values())
for key, value in cntByName.items():
    if value == maxCnt:
        candidates.append(key)

print("\n".join(sorted(candidates)))
