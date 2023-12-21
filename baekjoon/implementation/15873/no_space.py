import sys

if __name__ == '__main__':
    str_ = sys.stdin.readline()

    ans = 0
    if str_[:2] == '10':
        ans = 10 + int(str_[2:])
    else:
        ans = int(str_[0]) - int('0') + int(str_[1:])

    print(ans)
