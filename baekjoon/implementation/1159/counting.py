import sys

def readline(): return sys.stdin.readline()
line_cnt = int(readline())
alphabet_cnt = [0 for _ in range(26)]
for _ in range(line_cnt):
    name = readline()
    alphabet_cnt[ord(name[0]) - 97] += 1

to_print = ''
for i in range(26):
    if alphabet_cnt[i] >= 5:
        to_print += chr(i + 97)

if to_print:
    print(to_print)
else:
    print('PREDAJA')
