import sys

class Candidate:
    def __init__(self, candidate_num):
        self.candidate_num = candidate_num
        self.votes = [0 for _ in range(CANDIDATE_CNT + 1)]

    def __gt__(self, other):
        self_total = self.total_votes()
        other_total = other.total_votes()

        if self_total > other_total:
            return True
        elif self_total < other_total:
            return False

        for vote in range(3, 0, -1):
            if self.votes[vote] > other.votes[vote]:
                return True
            elif self.votes[vote] < other.votes[vote]:
                return False
        return False

    def __eq__(self, __value):
        for vote in range(3, 0, -1):
            if self.votes[vote] != __value.votes[vote]:
                return False
        return True

    def total_votes(self):
        total = 0
        for vote in range(3, 0, -1):
            total += self.votes[vote] * vote
        return total

if __name__ == '__main__':
    CANDIDATE_CNT = 3
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    vote_cnt = int(readline())
    candidates = [Candidate(i + 1) for i in range(CANDIDATE_CNT)]
    while vote_cnt:
        candidate_idx = 0
        for vote in splitIntoInt():
            candidates[candidate_idx].votes[vote] += 1
            candidate_idx += 1
        vote_cnt -= 1

    candidates.sort(reverse=True)
    if candidates[0] == candidates[1]:
        print(0, candidates[0].total_votes())
    else:
        print(candidates[0].candidate_num, candidates[0].total_votes())
