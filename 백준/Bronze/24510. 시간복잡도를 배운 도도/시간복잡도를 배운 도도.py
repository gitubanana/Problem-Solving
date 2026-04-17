ans = 0
n = int(input())
for _ in range(n):
    code = input()
    ans = max(ans, code.count('for') + code.count('while'))

print(ans)