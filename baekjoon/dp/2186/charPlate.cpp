#include <iostream>
#include <cstring>

const int FAIL = -1;
const int MAX_SIZE = 100;
const int MAX_DEPTH = 80;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, moveLimit;
char map[MAX_SIZE][MAX_SIZE + 1];
int dp[MAX_SIZE][MAX_SIZE][MAX_DEPTH];
std::string toMake;

int dfs(int y, int x, int depth=0)
{
    static const int depthLimit = toMake.size() - 1;

    int &curDp = dp[y][x][depth];
    if (curDp >= 0)
    {
        return (curDp);
    }

    if (depth == depthLimit)
    {
        return (curDp = 1);
    }

    int nextDepth = depth + 1;

    curDp = 0;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        for (int m = 1; m <= moveLimit; ++m)
        {
            int nextY = y + dy[dir] * m;
            int nextX = x + dx[dir] * m;

            if (!(0 <= nextY && nextY < ySize)
                || !(0 <= nextX && nextX < xSize))
            {
                break ;   
            }

            if (map[nextY][nextX] == toMake[nextDepth])
            {
                curDp += dfs(nextY, nextX, nextDepth);
            }
        }
    }

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> moveLimit;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }
    std::cin >> toMake;

    int ans = 0;

    memset(dp, -1, sizeof(dp));
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (toMake[0] != map[y][x])
                continue ;

            ans += dfs(y, x);
        }
    }

    std::cout << ans << '\n';
    return (0);
}
