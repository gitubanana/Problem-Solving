import sys

def findAndDel(cmp):
    global cnt

    key = max(cnt, key=cmp)
    del cnt[key]
    return key

line = lambda: sys.stdin.readline().strip()
num = lambda: int(line())

cnt = dict()
for _ in range(num()):
    n = num()
    cnt[n] = cnt.get(n, 0) + 1

maxValue = max(cnt.values())
if list(cnt.values()).count(maxValue) > 1:
    print(
        findAndDel(lambda key: (cnt[key], key))
        - findAndDel(lambda key: (cnt[key], -key))
    )
    sys.exit()

a = findAndDel(lambda key: (cnt[key], key))
b = findAndDel(lambda key: (cnt[key], key))
c = findAndDel(lambda key: (cnt[key], -key))
print(max(abs(a - b), abs(a - c)))
