import sys
import math

class Pos:
    def __init__(self, y, x):
        self.y = y
        self.x = x

    def __str__(self):
        return 'y : ' + str(self.y) + ', x : ' + str(self.x)

def countWays(positions: list[Pos]):
    ways = 1
    for i in range(1, len(positions)):
        yCnt = positions[i].y - positions[i - 1].y
        xCnt = positions[i].x - positions[i - 1].x
        ways *= math.factorial(yCnt + xCnt) // (math.factorial(yCnt) * math.factorial(xCnt))

    return ways

def main():
    ySize, xSize, via = map(int, sys.stdin.readline().split())
    positions = []

    via -= 1

    positions.append(Pos(0, 0))
    if via > 0:
        positions.append(Pos(via // xSize, via % xSize))
    positions.append(Pos(ySize - 1, xSize - 1))

    # for pos in positions:
    #     print(pos)
    print(countWays(positions))

main()
