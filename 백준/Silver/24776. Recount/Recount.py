cntByName = dict()
while True:
    name = input()
    if name == '***':
        break
    cntByName[name] = cntByName.get(name, 0) + 1

president = max(cntByName, key=cntByName.get)
presidentVote = cntByName[president]
if list(cntByName.values()).count(presidentVote) != 1:
    print('Runoff!')
else:
    print(president)
