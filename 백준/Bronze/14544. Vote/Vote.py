for t in range(1, int(input())+1):
    keyCnt, voteCnt = map(int, input().strip().split())
    voteByName = dict()
    for _ in range(keyCnt):
        voteByName[input()] = 0
    for _ in range(voteCnt):
        key, vote, _ = input().strip().split()
        voteByName[key] += int(vote)

    president = max(voteByName, key=voteByName.get)
    presidentVote = voteByName[president]
    if list(voteByName.values()).count(presidentVote) != 1:
        print(f'VOTE {t}: THERE IS A DILEMMA')
    else:
        print(f'VOTE {t}: THE WINNER IS {president} {presidentVote}')
