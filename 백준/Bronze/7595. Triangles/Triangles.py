while True:
    size = int(input())
    if size == 0:
        break

    for i in range(1, size+1):
        print('*'*i)