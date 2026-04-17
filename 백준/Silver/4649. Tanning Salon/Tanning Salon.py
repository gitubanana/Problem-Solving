while True:
    tokens = input().split()
    if tokens[0] == '0':
        break

    gone = 0
    bedCnt = int(tokens[0])
    inTheBed = [False]*26
    for ch in tokens[1]:
        idx = ord(ch) - ord('A')
        if inTheBed[idx]:
            bedCnt += 1
            continue

        if bedCnt == 0:
            gone += 1
            continue

        inTheBed[idx] = True
        bedCnt -= 1

    if gone == 0:
        print('All customers tanned successfully.')
    else:
        print(f'{gone // 2} customer(s) walked away.')
