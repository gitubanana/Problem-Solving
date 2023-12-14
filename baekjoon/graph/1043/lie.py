import sys

def get_parent(x: int) -> int:
    global parents

    if x == parents[x]:
        return x
    parents[x] = get_parent(parents[x])
    return parents[x]

def union(x: int, y: int) -> None:
    x_parent = get_parent(x)
    y_parent = get_parent(y)

    if x_parent > y_parent:
        parents[x_parent] = y_parent
    else:
        parents[y_parent] = x_parent

TO_AVOID = 0
readline = lambda: sys.stdin.readline()
splitIntoInt = lambda: map(int, readline().split())
v_cnt, party_cnt = splitIntoInt()
v_cnt += 1

parents = [0 for _ in range(v_cnt)]
for v in range(v_cnt):
    parents[v] = v

avoid_list = list(splitIntoInt())
for i in range(1, len(avoid_list)):
    union(avoid_list[i], TO_AVOID)

all_party = []
for _ in range(party_cnt):
    party_list = list(splitIntoInt())
    all_party.append(party_list)
    for i in range(2, len(party_list)):
        union(party_list[i - 1], party_list[i])

available_cnt = 0
for party_list in all_party:
    available = True
    for i in range(1, len(party_list)):
        if get_parent(party_list[i]) == TO_AVOID:
            available = False
            break
    available_cnt += available

print(available_cnt)
