n = input()
visited = set()
ans = 'HAPPY'

visited.add(n)
while True:
    num = 0
    for ch in n:
        num += (ord(ch) - ord('0'))**2

    n = str(num)
    if n == '1':
        break

    if n in visited:
        ans = 'UNHAPPY'
        break

    visited.add(n)

print(ans)
