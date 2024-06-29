#include <iostream>
#include <vector>

enum e_space
{
    EMPTY = '0',
    WALL
};

const int MAX_SIZE = 32;
const int64_t FAIL = -1;
const int dy[] = {0, 1, 1};
const int dx[] = {1, 0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const std::vector<int> typeDir[] = {
    {0, 2},
    {1, 2},
    {0, 1, 2}
};

int size;
char map[MAX_SIZE][MAX_SIZE];
int64_t dp[MAX_SIZE][MAX_SIZE][dirSize];

inline bool canGo(int nextY, int nextX, int dir)
{
    bool diagonalOk = true;
    if (dir == 2)
    {
        diagonalOk = (map[nextY - 1][nextX] != WALL
                    && map[nextY][nextX - 1] != WALL);
    }

    return (diagonalOk && map[nextY][nextX] != WALL);
}

int64_t dfs(int y=0, int x=1, int type=0)
{
    int64_t &curDp = dp[y][x][type];

    if (curDp == FAIL)
        return (0);

    if (curDp != 0)
        return (curDp);

    if (y == size - 1 && x == size - 1)
        return (curDp = 1);

    for (const int &dir : typeDir[type])
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size)
            || !canGo(nextY, nextX, dir))
            continue ;

        curDp += dfs(nextY, nextX, dir);
    }

    if (curDp == 0)
    {
        curDp = FAIL;
        return (0);
    }

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    std::cout << dfs() << '\n';
    return (0);
}
