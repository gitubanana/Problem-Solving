import sys

t = 1
line = lambda: sys.stdin.readline().strip()
while True:
    size = int(line())
    if size == 0:
        break

    zoo = dict()
    for _ in range(size):
        animal = line().split()[-1].lower()
        if animal in zoo:
            zoo[animal] += 1
        else:
            zoo[animal] = 1

    print(f'List {t}:')
    for key, value in sorted(zoo.items()):
        print(f'{key} | {value}')

    t += 1
    
