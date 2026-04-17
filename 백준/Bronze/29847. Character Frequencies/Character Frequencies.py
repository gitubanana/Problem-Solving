cntByChar = dict()
for _ in range(int(input())):
    for ch in input():
        if ch.isspace():
            continue
        cntByChar[ch] = cntByChar.get(ch, 0) + 1

for key, value in sorted(cntByChar.items()):
    print(f'{key} {value}')