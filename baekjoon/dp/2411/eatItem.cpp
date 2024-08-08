#include <iostream>
#include <cstring>

enum e_space
{
    EMPTY = 0,
    ITEM,
    WALL
};

const int MAX_SIZE = 101;
const int MAX_ITEM = 100 * 2;
const int dy[] = {1, 0};
const int dx[] = {0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int itemCnt;
int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][MAX_ITEM];

int dfs(int y=1, int x=1, int gotCnt=0)
{
    if (y == ySize && x == xSize)
    {
        return (gotCnt == itemCnt);
    }

    int &curDp = dp[y][x][gotCnt];
    if (curDp != -1)
    {
        return (curDp);
    }

    curDp = 0;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (nextY > ySize
            || nextX > xSize
            || map[nextY][nextX] == WALL)
            continue ;

        curDp += dfs(nextY, nextX, gotCnt + (map[nextY][nextX] == ITEM));
    }

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int wallCnt;

    std::cin >> ySize >> xSize >> itemCnt >> wallCnt;
    for (int i = 0; i < itemCnt; ++i)
    {
        int y, x;

        std::cin >> y >> x;
        map[y][x] = ITEM;
    }
    while (wallCnt--)
    {
        int y, x;

        std::cin >> y >> x;
        map[y][x] = WALL;
    }

    memset(dp, -1, sizeof(dp));
    std::cout << dfs() << '\n';
    return (0);
}
