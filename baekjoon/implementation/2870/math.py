import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()

    arr = []
    test_cnt = int(readline())
    while test_cnt:
        num = 0
        is_number = False
        for ch in readline():
            if ch.isdigit():
                num = num * 10 + int(ch)
                is_number = True
            elif is_number:
                arr.append(num)
                is_number = False
                num = 0
        test_cnt -= 1

    arr.sort()
    for num in arr:
        print(num)
