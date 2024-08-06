#include <iostream>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

const int MAX_SIZE = 100;

int ySize, xSize;
int curIdx, nextIdx;
int map[2][MAX_SIZE][MAX_SIZE];

void    upsideDown(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[ySize - y - 1][x];
        }
    }
}

void    switchSides(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][xSize - x - 1];
        }
    }
}

void    rotateRight90(void)
{
    for (int y = 0; y < xSize; ++y)
    {
        for (int x = 0; x < ySize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[ySize - x - 1][y];
        }
    }
    std::swap(ySize, xSize);
}

void    rotateLeft90(void)
{
    for (int y = 0; y < xSize; ++y)
    {
        for (int x = 0; x < ySize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[x][xSize - y - 1];
        }
    }
    std::swap(ySize, xSize);
}

void    rotateGroupClockWise(void)
{
    int halfY = ySize / 2;
    int halfX = xSize / 2;

    for (int y = 0; y < halfY; ++y)
    {
        for (int x = 0; x < halfX; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y + halfY][x];
        }
    }

    for (int y = 0; y < halfY; ++y)
    {
        for (int x = halfX; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][x - halfX];
        }
    }

    for (int y = halfY; y < ySize; ++y)
    {
        for (int x = halfX; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y - halfY][x];
        }
    }

    for (int y = halfY; y < ySize; ++y)
    {
        for (int x = 0; x < halfX; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][x + halfX];
        }
    }
}

void    rotateGroupCounterClockWise(void)
{
    int halfY = ySize / 2;
    int halfX = xSize / 2;

    for (int y = 0; y < halfY; ++y)
    {
        for (int x = 0; x < halfX; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][x + halfX];
        }
    }

    for (int y = 0; y < halfY; ++y)
    {
        for (int x = halfX; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y + halfY][x];
        }
    }

    for (int y = halfY; y < ySize; ++y)
    {
        for (int x = halfX; x < xSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][x - halfX];
        }
    }

    for (int y = halfY; y < ySize; ++y)
    {
        for (int x = 0; x < halfX; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y - halfY][x];
        }
    }
}

void    doCmd(int cmd)
{
    switch (cmd)
    {
    case 1:
        upsideDown();
        break;
    case 2:
        switchSides();
        break;
    case 3:
        rotateRight90();
        break;
    case 4:
        rotateLeft90();
        break;
    case 5:
        rotateGroupClockWise();
        break;
    case 6:
        rotateGroupCounterClockWise();
        break;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> ySize >> xSize >> cmdCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }
    while (cmdCnt--)
    {
        int cmd;

        std::cin >> cmd;
        nextIdx = curIdx ^ 1;
        doCmd(cmd);
        curIdx = nextIdx;
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cout << CURMAP[y][x] << ' ';
        }
        std::cout << '\n';
    }
    return (0);
}
