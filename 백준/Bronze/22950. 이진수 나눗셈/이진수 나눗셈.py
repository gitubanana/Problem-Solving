size = int(input())
bits = input()
border = size - int(input())

ans = 'NO'
if (bits.count('1', border, size) == 0):
    ans = 'YES'

print(ans)
