import sys

def count_withdraw(withdraw_money):
    ret = 0
    i_have = 0
    for need in needs:
        if i_have < need:
            i_have = withdraw_money
            ret += 1
        i_have -= need
        if i_have < 0:
            return cnt + 1
    return ret

readline = lambda: sys.stdin.readline()
size, cnt = map(int, readline().split())
needs = [int(readline()) for _ in range(size)]

left = 1
right = 1_000_000_000
min_ = right
while left <= right:
    mid = (left + right) // 2
    if count_withdraw(mid) <= cnt:
        min_ = min(min_, mid)
        right = mid - 1
    else:
        left = mid + 1

print(min_)
