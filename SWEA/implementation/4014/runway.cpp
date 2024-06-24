#include <iostream>

const int MAX_SIZE = 20;
const int dy[] = {1, 0};
const int dx[] = {0, 1};

int size, slopeWidth;
int map[MAX_SIZE][MAX_SIZE];

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < size)
            && (0 <= x && x < size));
}

inline bool canInstallSlope(int y, int x, int dir)
{
    const int &curHeight = map[y][x];

    int sameHeightSize = slopeWidth;
    while (--sameHeightSize)
    {
        y += dy[dir];
        x += dx[dir];

        if (!isBound(y, x) || curHeight != map[y][x])
            return (false);
    }
    return (true);
}

bool canBeRunway(int y, int x, int dir)
{
    while (isBound(y, x))
    {
        int &curHeight = map[y][x];
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        while (isBound(nextY, nextX))
        {
            int &nextHeight = map[nextY][nextX];
            if (curHeight != nextHeight)
                break ;

            nextY += dy[dir];
            nextX += dx[dir];
        }
        if (!isBound(nextY, nextX))
            break ;

        int nextHeight = map[nextY][nextX];
        if (nextHeight == curHeight + 1)
        {
            if (!canInstallSlope(y, x, dir))
                return (false);

            y = nextY;
            x = nextX;
        }
        else if (nextHeight == curHeight - 1)
        {
            if (!canInstallSlope(nextY, nextX, dir))
                return (false);

            y = nextY + dy[dir] * slopeWidth;
            x = nextX + dx[dir] * slopeWidth;
            while (isBound(y, x))
            {
                if (map[y][x] == nextHeight - 1)
                {
                    if (!canInstallSlope(y, x, dir))
                        return (false);

                    nextHeight = map[y][x];
                    y = y + dy[dir] * slopeWidth;
                    x = x + dx[dir] * slopeWidth;
                }
                else if (map[y][x] == nextHeight)
                {
                    break ;
                }
                else if (map[y][x] != nextHeight)
                {
                    return (false);
                }
            }
        }
        else
        {
            return (false);
        }
    }
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size >> slopeWidth;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                std::cin >> map[y][x];
            }
        }

        int runwayCnt = 0;
        for (int pos = 0; pos < size; ++pos)
        {
            runwayCnt += canBeRunway(pos, 0, 1);
            runwayCnt += canBeRunway(0, pos, 0);
        }

        std::cout << "#" << t << ' ' << runwayCnt << '\n';
    }
    return (0);
}
