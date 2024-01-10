import sys

def match_pattern(name: str) -> bool:
    if len(name) < pattern_len - 1:
        return False

    i = 0
    while pattern[i] != '*':
        if name[i] != pattern[i]:
            return False
        i += 1

    i = -1
    while pattern[i] != '*':
        if name[i] != pattern[i]:
            return False
        i -= 1
    return True

def readline(): return sys.stdin.readline()

test_cnt = int(readline())
pattern = readline().strip()
pattern_len = len(pattern)
for _ in range(test_cnt):
    print("DA" if match_pattern(sys.stdin.readline().strip()) else "NE")
