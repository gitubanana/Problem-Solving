def isPrime(n):
    if n <= 1:
        return False

    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

print('SAFE' if isPrime(int(input())) else 'BROKEN')
