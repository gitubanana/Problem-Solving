import sys

if __name__ == '__main__':
    def readline(): return sys.stdin.readline()
    def splitIntoInt(): return map(int, readline().split())

    size, _ = splitIntoInt()
    cnt_dict = dict()

    for num in splitIntoInt():
        if num not in cnt_dict:
            cnt_dict[num] = 1
        else:
            cnt_dict[num] += 1

    cnt_dict = sorted(cnt_dict.items(), key=lambda x: x[1], reverse=True)
    for num, cnt in cnt_dict:
        for _ in range(cnt):
            print(num, end=' ')
    print()
