names = ('Mary', 'John')

while True:
    n = input()
    if n == '0':
        break

    winCnt = [0] * len(names)
    for i in map(int, input().split()):
        winCnt[i] += 1

    result = []
    for i in range(0, len(names)):
        result.append(f'{names[i]} won {winCnt[i]} times')

    print(' and '.join(result))
