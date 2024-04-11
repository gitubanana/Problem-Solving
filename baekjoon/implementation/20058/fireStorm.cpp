#include <iostream>
#include <cmath>
#define CURMAP map[mapIdx]
#define NEXTMAP map[nextMapIdx]

const int MAX = (1 << 6);
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

bool visited[MAX][MAX];
int map[2][MAX][MAX];
int mapSize, mapIdx, nextMapIdx;

void    dfs(int y, int x, int &totalIce, int &icebergSize)
{
    ++icebergSize;
    totalIce += CURMAP[y][x];
    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < mapSize)
            || !(0 <= nextX && nextX < mapSize)
            || visited[nextY][nextX]
            || CURMAP[nextY][nextX] <= 0)
            continue ;

        dfs(nextY, nextX, totalIce, icebergSize);
    }
}

void    printAnswers(void)
{
    int totalIce = 0;
    int largestIcebergSize = 0;

    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            if (!visited[y][x] && CURMAP[y][x] > 0)
            {
                int icebergSize = 0;
                
                dfs(y, x, totalIce, icebergSize);
                if (largestIcebergSize < icebergSize)
                    largestIcebergSize = icebergSize;
            }
        }
    }

    std::cout << totalIce << '\n';
    std::cout << largestIcebergSize << '\n';
}

int countAdjacentIce(int y, int x)
{
    int iceCnt = 0;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < mapSize)
            || !(0 <= nextX && nextX < mapSize)
            || CURMAP[nextY][nextX] <= 0)
            continue ;

        ++iceCnt;
    }
    return (iceCnt);
}

void    moveIce(int y, int x, int step)
{
    int nextY = y;
    int nextX = x + step - 1;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextDir = (dir + 1) % dirSize;

        for (int i = 1; i < step; ++i)
        {
            NEXTMAP[nextY][nextX] = CURMAP[y][x];

            y += dy[dir];
            x += dx[dir];
            nextY += dy[nextDir];
            nextX += dx[nextDir];
        }
    }
}

void    turn90degree(int startY, int startX, int step)
{
    while (step > 1)
    {
        moveIce(startY, startX, step);
        ++startY, ++startX;
        step -= 2;
    }
}

void    fireStorm(int level)
{
    if (level > 0)
    {
        int step = (1 << level);

        nextMapIdx = (mapIdx + 1) % 2;
        for (int y = 0; y < mapSize; y += step)
        {
            for (int x = 0; x < mapSize; x += step)
            {
                turn90degree(y, x, step);
            }
        }
        mapIdx = nextMapIdx;
    }

    nextMapIdx = (mapIdx + 1) % 2;
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            NEXTMAP[y][x] = CURMAP[y][x] - (CURMAP[y][x] > 0 && countAdjacentIce(y, x) < 3);
        }
    }
    mapIdx = nextMapIdx;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> mapSize >> cmdCnt;
    mapSize = (1 << mapSize);
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }

    int level;
    while (cmdCnt--)
    {
        std::cin >> level;
        fireStorm(level);
    }

    printAnswers();
    return (0);
}
