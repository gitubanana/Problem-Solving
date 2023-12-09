import sys
import math

# is_panlindrome and is_prime

def is_prime(x: int) -> bool:
    if x == 1:
        return False

    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

def is_panlindrome(x: str) -> bool:
    size = len(x)
    end = size - 1
    for start in range(size // 2):
        if x[start] != x[end]:
            return False
        end -= 1
    return True

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    while True:
        if (is_panlindrome(str(n))
            and is_prime(n)):
            break
        n += 1
    print(n)
