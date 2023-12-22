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

    test_cnt = int(readline())
    while test_cnt:
        arr = list(splitIntoInt())
        sum_ = 0
        for i in range(1, arr[0] + 1):
            for j in range(i + 1, arr[0] + 1):
                sum_ += gcd(arr[i], arr[j])
        print(sum_)
        test_cnt -= 1
