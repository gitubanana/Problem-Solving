#include <iostream>

const int MAX_SIZE = 1000;
const int DIVISOR = 1e9 + 7;
const int dy[] = {1, 1, 0};
const int dx[] = {1, 0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]); 

int ySize, xSize;
int dp[MAX_SIZE][MAX_SIZE];

int dfs(int y=0, int x=0)
{
    if (y == ySize - 1 && x == xSize - 1)
        return 1;

    int &curDp = dp[y][x];
    if (curDp != 0)
        return curDp;

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize))
            continue;

        curDp += dfs(nextY, nextX);
        curDp %= DIVISOR;
    }

    return curDp;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    std::cout << dfs() << '\n';
    return 0;
}
