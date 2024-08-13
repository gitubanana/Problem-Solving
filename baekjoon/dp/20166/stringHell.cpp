#include <iostream>
#include <cstring>

const int MAX_SIZE = 10;
const int MAX_DEPTH = 5;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char str[MAX_DEPTH + 1];
char map[MAX_SIZE][MAX_SIZE + 1];
int dp[MAX_SIZE][MAX_SIZE][MAX_DEPTH];

int dfs(int y, int x, int depth=1)
{
    if (str[depth] == 0)
        return (1);

    int &curDp = dp[y][x][depth];
    if (curDp != -1)
        return (curDp);

    curDp = 0;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = (y + dy[dir] + ySize) % ySize;
        int nextX = (x + dx[dir] + xSize) % xSize;

        if (map[nextY][nextX] != str[depth])
            continue ;

        curDp += dfs(nextY, nextX, depth + 1);
    }

    return (curDp);
}

int findStrCnt(void)
{
    int strCnt = 0;

    memset(dp, -1, sizeof(dp));
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] != str[0])
                continue ;

            strCnt += dfs(y, x);
        }
    }

    return (strCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int findCnt;

    std::cin >> ySize >> xSize >> findCnt;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    while (findCnt--)
    {
        std::cin >> str;
        std::cout << findStrCnt() << '\n';
    }
    return (0);
}