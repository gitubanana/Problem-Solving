size, totalMoney = map(int, input().split())
cnts = list([int(input()) for _ in range(size)])
unitMoney = totalMoney // sum(cnts)

print(*[cnt*unitMoney for cnt in cnts], sep='\n')
