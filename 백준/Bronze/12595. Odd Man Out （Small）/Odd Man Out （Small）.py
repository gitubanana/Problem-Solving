for t in range(1, int(input()) + 1):
    input()
    s = set()
    for c in input().split():
        if c in s:
            s.remove(c)
        else:
            s.add(c)

    for n in s:
        print(f'Case #{t}: {n}')
