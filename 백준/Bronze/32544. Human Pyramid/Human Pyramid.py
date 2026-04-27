n = int(input())

ans = 1
L, R = 1, 1e12
while L <= R:
    M = (L+R) // 2
    if M*(M+1)//2 <= n:
        ans = M
        L = M+1
    else:
        R = M-1

print(int(ans))
