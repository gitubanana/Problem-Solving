exists = [False for _ in range(26)] 
for _ in range(int(input())):
    exists[ord(input()[0]) - 65] = True

ans = 0
while True:
    if not exists[ans] or (ans := ans+1) == 26:
        break

print(ans)
