#include <iostream>
#include <cstring>

const int MAX_SIZE = 8;
const int MAX_MINUS = 5;
const int INIT_VALUE = 0;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int height[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int size, maxMinus;

int    backTracking(int y, int x, int curHeight, bool didMinus=false)
{
    int plus = 0;
    int limitMinus = maxMinus * !didMinus;

    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size)
            || visited[nextY][nextX])
            continue ;

        for (int minus = 0; minus <= limitMinus; ++minus)
        {
            int nextHeight = height[nextY][nextX] - minus;
            if (nextHeight >= curHeight)
                continue ;

            plus = std::max(
                plus,
                backTracking(nextY, nextX, nextHeight, (minus != 0) | didMinus)
            );
        }
    }
    visited[y][x] = false;

    return (plus + 1);
}

int findMaxTrail(int maxHeight)
{
    int maxTrail = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            const int &curHeight = height[y][x];

            if (curHeight != maxHeight)
                continue ;

            maxTrail = std::max(
                maxTrail,
                backTracking(y, x, curHeight)
            );

        }
    }

    return (maxTrail);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int maxHeight = 0;

        std::cin >> size >> maxMinus;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                int &curHeight = height[y][x];

                std::cin >> curHeight;
                maxHeight = std::max(maxHeight, curHeight);
            }
        }

        std::cout << '#' << t << ' ' << findMaxTrail(maxHeight) << '\n';
    }
    return (0);
}
