import sys, math

def is_prime_number(x: int) -> bool:
    if x == 1:
        return False

    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0:
            return False
    return True

def back_tracking(cur, depth=0):
    global arr

    if depth == LIMIT:
        print(cur)
        return

    for num in range(1, 10):
        next = cur * 10 + num
        if not is_prime_number(next):
            continue
        back_tracking(next, depth + 1)

if __name__ == '__main__':
    LIMIT = int(sys.stdin.readline())
    back_tracking(0)
