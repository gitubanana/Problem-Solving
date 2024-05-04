#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX][MAX];
int cnt[MAX][MAX];

int    dfs(int y=0, int x=0)
{
    if ((y == ySize - 1 && x == xSize - 1)
        || (cnt[y][x] > 0))
        return (cnt[y][x]);

    if (cnt[y][x] == -1)
        return (0);

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize)
            || map[y][x] <= map[nextY][nextX])
            continue ;

        cnt[y][x] += dfs(nextY, nextX);
    }
    if (cnt[y][x] == 0)
    {
        cnt[y][x] = -1;
        return (0);
    }
    return cnt[y][x];
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
            std::cin >> map[y][x];
    }

    cnt[ySize - 1][xSize - 1] = 1;
    std::cout << ((ySize == 1 && xSize == 1) ? 1 : dfs()) << '\n';
    return (0);
}
