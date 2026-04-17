import sys

sum = int(input())
cntBySpecies = dict()
for _ in range(sum):
    species = input()
    cntBySpecies[species] = cntBySpecies.get(species, 0) + 1

for key, value in cntBySpecies.items():
    if value > sum - value:
        print(key)
        sys.exit()

print('NONE')
