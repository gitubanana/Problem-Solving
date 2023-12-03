import sys

def get_acgt_cnt(dna, size):
    ret = [0, 0, 0, 0]
    for i in range(size):
        ret[acgt.index(dna[i])] += 1
    return ret

def is_possible(a, b, size):
    for i in range(size):
        if a[i] > b[i]:
            return False
    return True

if __name__ == '__main__':
    splitIntoInt = lambda: map(int, sys.stdin.readline().split())
    size, pw_size = splitIntoInt()
    dna = sys.stdin.readline()
    ACGT_CNT = list(splitIntoInt())

    acgt = "ACGT"
    cur_cnt = get_acgt_cnt(dna, pw_size)
    cnt = 0 + is_possible(ACGT_CNT, cur_cnt, 4)
    for i in range(size - pw_size):
        cur_cnt[acgt.index(dna[i])] -= 1
        cur_cnt[acgt.index(dna[i + pw_size])] += 1
        cnt += is_possible(ACGT_CNT, cur_cnt, 4)

    print(cnt)
