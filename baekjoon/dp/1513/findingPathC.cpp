#include <iostream>
#include <cstring>
#include <vector>

const int MAX_SIZE = 50;
const int MAX_GAME = 50;
const int DIVISOR = 1'000'007;

int ySize, xSize, gameCnt, shouldPass;
int map[MAX_SIZE + 1][MAX_SIZE + 1];
int dp[MAX_SIZE + 1][MAX_SIZE + 1][MAX_GAME + 1][MAX_GAME + 1];

int dfs(int y, int x, int prevSpace, int remainPass)
{
    if (!(1 <= y && y <= ySize)
        || !(1 <= x && x <= xSize)
        || remainPass < 0)
        return (0);

    int &curSpace = map[y][x];
    int &curDp = dp[y][x][prevSpace][remainPass];

    if (curDp != -1)
    {
        return (curDp);
    }

    if (y == ySize && x == xSize)
    {
        if (!(remainPass == 0 && curSpace == 0)
            && !(remainPass == 1 && curSpace > prevSpace))
           return (0);

        return (curDp = 1);
    }

    curDp = 0;
    if (curSpace == 0)
    {
        curDp = dfs(y + 1, x, prevSpace, remainPass)
                + dfs(y, x + 1, prevSpace, remainPass);
    }
    else if (curSpace > prevSpace)
    {
        curDp = dfs(y + 1, x, curSpace, remainPass - 1)
                + dfs(y, x + 1, curSpace, remainPass - 1);
    }

    return (curDp %= DIVISOR);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> gameCnt;
    for (int id = 1; id <= gameCnt; ++id)
    {
        int y, x;

        std::cin >> y >> x;
        map[y][x] = id;
    }

    memset(dp, -1, sizeof(dp));
    for (; shouldPass <= gameCnt; ++shouldPass)
    {
        std::cout << dfs(1, 1, 0, shouldPass) << ' ';
    }
    std::cout << '\n';
    return (0);
}
