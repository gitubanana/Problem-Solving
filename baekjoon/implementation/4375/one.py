import sys

for n in map(int, sys.stdin.read().strip().split('\n')):
    len_ = 1
    dividend = 1
    while dividend % n:
        dividend = dividend * 10 + 1
        len_ += 1
    print(len_)
