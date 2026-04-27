def reversed(pos, start, end):
    if not start <= pos <= end:
        return pos

    return end - (pos - start)

size, pos, cmdCnt = map(int, input().split())
input()

for _ in range(cmdCnt):
    cmd = int(input())
    if cmd > 0:
        pos = reversed(pos, 1, cmd)
    else:
        pos = reversed(pos, size+cmd+1, size)

print(pos)
