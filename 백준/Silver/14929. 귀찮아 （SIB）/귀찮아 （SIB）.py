size = int(input())
arr = [0] + list(map(int, input().split()))
sum = [0 for _ in range(size+1)]

for i in range(1, size+1):
    sum[i] = sum[i-1]+arr[i]

ans = 0
for i in range(1, size+1):
    ans += arr[i] * (sum[size] - sum[i])

print(ans)

# a1a2 + a1a3 + ... + a1an = a1(a2 + a3 + ... + an)
# a2a3 + a2a4 + ... + a2an = a2(a3 + a4 + ... + an)
# axa(x+1) + axa(x+2) + ... + axan = ax(a(x+1) + ... + an)
