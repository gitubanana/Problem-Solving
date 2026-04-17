coins = [25, 10, 5, 1]
change = 100 - int(input())
for coin in coins:
    print(change // coin, end=' ')
    change %= coin
