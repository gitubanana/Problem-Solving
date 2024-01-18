import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    test_cnt = int(readline())
    while test_cnt:
        n = int(readline())
        five = 5
        zero_cnt = 0
        while five <= n:
            zero_cnt += n // five
            five *= 5
        print(zero_cnt)

        test_cnt -= 1
