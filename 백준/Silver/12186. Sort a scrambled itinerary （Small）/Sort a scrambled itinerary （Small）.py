from collections import deque

for t in range(1, int(input())+1):
    toByFrom = dict()
    fromByTo = dict()
    for _ in range(int(input())):
        src, dest = input(), input()
        toByFrom[src] = dest
        fromByTo[dest] = src

    itinerary = deque()
    start = next(iter(toByFrom))
    itinerary.append(start+'-'+toByFrom[start])

    prevCity = start
    while prevCity in fromByTo:
        itinerary.appendleft(fromByTo[prevCity]+'-'+prevCity)
        prevCity = fromByTo[prevCity]

    nextCity = toByFrom[start] # next로 하면, next(iter)라 충돌남
    while nextCity in toByFrom:
        itinerary.append(nextCity+'-'+toByFrom[nextCity])
        nextCity = toByFrom[nextCity]

    print(f'Case #{t}: {" ".join(itinerary)}')
