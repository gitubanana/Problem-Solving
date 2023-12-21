import sys


def gcd(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b


if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    size = int(readline())
    arr = list(splitIntoInt())
    gcd_ = gcd(arr[0], arr[1])
    for i in range(2, size):
        gcd_ = gcd(gcd_, arr[i])

    ans = []
    for divisor in range(1, int(gcd_ ** 0.5) + 1):
        if gcd_ % divisor == 0:
            ans.append(divisor)
            if divisor ** 2 != gcd_:
                ans.append(gcd_ // divisor)

    ans.sort()
    for c_d in ans:
        print(c_d)
