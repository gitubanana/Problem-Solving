def nextModulo(L, R):
    global nexts, arr
    for i in range(L - 1, R):
        arr[i] = nexts[arr[i]]

modulo = 2010
nexts = [0] * modulo 
for i in range(modulo):
    nexts[i] = (i * i) % modulo

input()
arr = list(map(int, input().split()))
for _ in range(int(input())):
    type, L, R = map(int, input().split())
    if type == 1:
        nextModulo(L, R)
    else:
        print(sum(arr[L-1:R]))
