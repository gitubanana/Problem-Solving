#include <iostream>
#include <cstring>
#include <algorithm>
#define CURMAP map[mapIdx]
#define NEXTMAP map[nextMapIdx]

enum e_space
{
    REMOVED = -2,
    BLACK,
    RAINBOW
};

struct t_group
{
    int y;
    int x;
    int blockCnt;
    int rainbowCnt;

    inline bool operator<(const t_group &other) const
    {
        if (this->blockCnt != other.blockCnt)
            return (this->blockCnt < other.blockCnt);

        if (this->rainbowCnt != other.rainbowCnt)
            return (this->rainbowCnt < other.rainbowCnt);

        if (this->y != other.y)
            return (this->y < other.y);

        return (this->x < other.x);
    }
};

const int MAX = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int score;
int mapSize, mapIdx, nextMapIdx;
int map[2][MAX][MAX];
bool visited[MAX][MAX];
const int visitedSize = sizeof(visited);

void    dfs(int y, int x, t_group &group, int color)
{
    const int &curSpace = CURMAP[y][x];

    ++group.blockCnt;
    group.rainbowCnt += (curSpace == RAINBOW);
    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < mapSize)
            || !(0 <= nextX && nextX < mapSize)
            || visited[nextY][nextX])
            continue ;

        const int &nextSpace = CURMAP[nextY][nextX];
        if (nextSpace == RAINBOW || nextSpace == color)
            dfs(nextY, nextX, group, color);
    }
}

void    initRainbowVisited(void)
{
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            if (CURMAP[y][x] == RAINBOW)
                visited[y][x] = false;
        }
    }
}

void    findLargestGroup(t_group &toSet)
{
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            if (!visited[y][x] && CURMAP[y][x] > RAINBOW)
            {
                t_group cmp = {y, x, 0, 0};

                initRainbowVisited();
                dfs(y, x, cmp, CURMAP[y][x]);
                if (cmp.blockCnt >= 2 && toSet < cmp)
                    toSet = cmp;
            }
        }
    }
}

void    removeGroup(int y, int x, int color)
{
    int &curSpace = CURMAP[y][x];

    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < mapSize)
            || !(0 <= nextX && nextX < mapSize)
            || visited[nextY][nextX])
            continue ;

        const int &nextSpace = CURMAP[nextY][nextX];
        if (nextSpace == RAINBOW || nextSpace == color)
            removeGroup(nextY, nextX, color);
    }
    curSpace = REMOVED;
}

inline int getDownY(int y, int x)
{
    while (true)
    {
        int nextY = y + 1;

        if (nextY >= mapSize || CURMAP[nextY][x] != REMOVED)
            break ;

        y = nextY;
    }
    return (y);
}

void    runGravity(void)
{
    for (int y = mapSize - 2; y >= 0; --y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            int &goingDown = CURMAP[y][x];

            if (goingDown == BLACK || goingDown == REMOVED)
                continue ;

            std::swap(goingDown, CURMAP[getDownY(y, x)][x]);
        }
    }
}

void    turn90degree(void)
{
    nextMapIdx = (mapIdx + 1) % 2;
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            NEXTMAP[mapSize - x - 1][y] = CURMAP[y][x];
        }
    }
    mapIdx = nextMapIdx;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int colorCnt;

    std::cin >> mapSize >> colorCnt;
    for (int y = 0; y < mapSize; ++y)
    {
        for (int x = 0; x < mapSize; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }

    while (true)
    {
        t_group largest = {0, 0, -1, 0};

        memset(visited, false, visitedSize);
        findLargestGroup(largest);
        if (largest.blockCnt == -1)
            break ;

        score += largest.blockCnt * largest.blockCnt;
        memset(visited, false, visitedSize);
        removeGroup(largest.y, largest.x, CURMAP[largest.y][largest.x]);

        runGravity();
        turn90degree();
        runGravity();
    }
    std::cout << score << '\n';
    return (0);
}
