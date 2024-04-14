#include <iostream>
#include <climits>
#define GET_MAX(a, b) (a) < (b) ? (b) : (a)
#define GET_MIN(a, b) (a) > (b) ? (b) : (a)

const int MAX = 500;
const int LIMIT = 4;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int maxSum;
int ySize, xSize;
int map[MAX][MAX];
bool visited[MAX][MAX];

void    dfs(int y, int x, int curSum, int depth=1)
{
    if (depth == LIMIT)
    {
        maxSum = GET_MAX(maxSum, curSum);
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
    int addibleCnt = 4;
    int cmp = map[y][x];
    int minNum = INT_MAX;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize))
        {
            --addibleCnt;
            minNum = 0;
            if (addibleCnt < 3)
                break ;
            continue ;
        }

        const int &toAdd = map[nextY][nextX];

        minNum = GET_MIN(minNum, toAdd);
        cmp += toAdd;
    }
    if (addibleCnt >= 3)
        maxSum = GET_MAX(maxSum, cmp - minNum);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

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
            dfs(y, x, map[y][x]);
            checkOh(y, x);
        }
    }

    std::cout << maxSum << '\n';
    return (0);
}
