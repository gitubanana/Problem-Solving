num = lambda: int(input())
cur, end = num(), num()
while True:
    print(f'All positions change in year {cur}')
    cur += 60
    if cur > end:
        break
