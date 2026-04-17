import math

def isPrime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def isSquare(n):
    if n < 0:
        return False
    sqrt = math.isqrt(n)
    return sqrt * sqrt == n

def P2(A):
    ans = 0
    for i in range(2, len(A)):
        if isPrime(i) and isSquare(A[i]):
            ans += A[i]
    return ans

