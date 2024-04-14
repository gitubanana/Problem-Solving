#include <iostream>

const int MAX = 500;
const int LIMIT = 4;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxSum;
int ySize, xSize;
int map[MAX][MAX];
bool visited[MAX][MAX];

void    dfs(int y, int x, int curSum=0, int depth=0)
{
    if (depth == LIMIT)
    {
        maxSum = std::max(maxSum, curSum);
        return ;
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

        dfs(nextY, nextX, curSum + map[nextY][nextX], depth + 1);
    }
    visited[y][x] = false;
}

void    checkOh(int y, int x)
{
    for (int startDir = 0; startDir < dirSize; ++startDir)
    {
        int cmp = map[y][x];
        int dirCnt = 3;
        int dir = startDir;

        while (dirCnt--)
        {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (!(0 <= nextY && nextY < ySize)
                || !(0 <= nextX && nextX < xSize))
                break ;

            cmp += map[nextY][nextX];
            dir = (dir + 1) % dirSize;
        }

        if (dirCnt == -1)
            maxSum = std::max(maxSum, cmp);
    }
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
        }
    }

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            dfs(y, x);
            checkOh(y, x);
        }
    }

    std::cout << maxSum << '\n';
    return (0);
}
