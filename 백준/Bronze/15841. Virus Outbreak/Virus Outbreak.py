fibo = [0, 1]
while True:
    n = int(input())
    if n == -1:
        break

    while n >= len(fibo):
        fibo.append(fibo[-1]+fibo[-2])

    print(f'Hour {n}: {fibo[n]} cow(s) affected')
