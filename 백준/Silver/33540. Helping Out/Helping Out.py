scoreByName = dict()
for _ in range(int(input())):
    name, score = input().split()
    scoreByName[name] = scoreByName.get(name, 0) + int(score)

for item in sorted(scoreByName.items(), key=lambda item: item[0]):
    print(*item)
