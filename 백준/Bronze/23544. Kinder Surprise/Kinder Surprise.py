total = int(input())
set = set()
for _ in range(total):
    set.add(input())

print(total - len(set))