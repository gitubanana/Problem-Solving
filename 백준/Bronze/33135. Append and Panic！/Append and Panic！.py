s = input().strip()
start = len(s)-1
for i in range(len(s)-1, 1, -1):
    if ord(s[i-1]) >= ord(s[i]):
        start = i
        break

print(start)
