import sys

def get_scored_sec():
    global scored_time

    splited = scored_time.split(':')
    return int(splited[0]) * 60 + int(splited[1])

def print_winning_time(idx):
    minute = winning_sec[idx] // 60
    second = winning_sec[idx] % 60
    print(minute // 10, minute % 10, ':', second // 10, second % 10, sep='')

if __name__ == '__main__':
    TEAM_CNT = 2
    def readline(): return sys.stdin.readline()

    score = [0] * (TEAM_CNT)
    winning_sec = [0] * (TEAM_CNT)
    score_cnt = int(readline())
    while score_cnt:
        winning_team, scored_time = readline().split()
        winning_team = int(winning_team) - 1
        not_winning_team = (winning_team + 1) % 2
        winning_time = get_scored_sec()
        score[winning_team] += 1
        score_cnt -= 1

        while score_cnt:
            scored_team, scored_time = readline().split()
            scored_team = int(scored_team) - 1
            scored_time = get_scored_sec()
            score[scored_team] += 1
            score_cnt -= 1
            if score[winning_team] == score[not_winning_team]:
                winning_sec[winning_team] += scored_time - winning_time
                break

    if score[0] != score[1]:
        winning_sec[winning_team] += 48 * 60 - winning_time

    for team in range(TEAM_CNT):
        print_winning_time(team)
