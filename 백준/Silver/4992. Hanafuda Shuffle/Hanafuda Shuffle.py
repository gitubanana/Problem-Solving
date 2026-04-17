while True:
    size, opCnt = map(int, input().split())
    if size == 0:
        break

    deck = [i for i in range(1, size+1)]
    for _ in range(opCnt):
        boundary, cnt = map(int, input().split())
        slice = deck[size-boundary-cnt+1:size-boundary+1]
        del deck[size-boundary-cnt+1:size-boundary+1]
        deck.extend(slice)

    print(deck[-1])