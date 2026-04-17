subSet = set()
subSize = int(input().split()[0])
str = input()
for i in range(len(str) - subSize + 1):
    subSet.add(str[i:i+subSize])

print(len(subSet))
