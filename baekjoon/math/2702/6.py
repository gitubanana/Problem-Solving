import sys

def get_gcd(a, b):
    while a != 0 and b != 0:
        if a > b:
            a %= b
        else:
            b %= a
    return a + b

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    test_cnt = int(readline())
    while test_cnt:
        a, b = splitIntoInt()
        gcd = get_gcd(a, b)
        print((a * b) // gcd, gcd)
        test_cnt -= 1
