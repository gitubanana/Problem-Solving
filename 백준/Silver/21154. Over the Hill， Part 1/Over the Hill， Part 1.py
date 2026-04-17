import sys
import math

chs = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 "

readline = lambda: sys.stdin.readline().strip()
size = int(readline())
matrix = [list(map(int, readline().split())) for _ in range(size)]
plainText = list(readline())
for i in range(len(plainText), math.ceil(len(plainText) / size) * size):
    plainText.append(' ')

cipherText = []
for start in range(0, len(plainText), size):
    for y in range(0, size):
        num = 0
        for x in range(0, size):
            num += chs.index(plainText[start + x]) * matrix[y][x]
            num %= 37
        cipherText.append(chs[num])

print("".join(cipherText))
