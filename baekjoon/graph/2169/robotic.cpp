#include <iostream>
#include <algorithm>

const int MAX_SIZE = 1000;
const int MIN = -1e8;
const int dy[] = {0, 0, 1};
const int dx[] = {-1, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE][dirSize];
bool visited[MAX_SIZE][MAX_SIZE];

int    dfs(int y, int x, int prevDir=0)
{
    if (y == ySize - 1 && x == xSize - 1)
    {
        return map[ySize - 1][xSize - 1];
    }

    int &curDp = dp[y][x][prevDir];
    if (curDp != MIN)
    {
        return curDp;
    }

    visited[y][x] = true;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize)
            || visited[nextY][nextX])
            continue ;

        curDp = std::max(
            curDp,
            map[y][x] + dfs(nextY, nextX, dir)
        );
    }

    visited[y][x] = false;
    return curDp;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
            for (int dir = 0; dir < dirSize; ++dir)
            {
                dp[y][x][dir] = MIN;
            }
        }
    }

    std::cout << dfs(0, 0) << '\n';
    return (0);
}
