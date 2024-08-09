#include <iostream>

enum e_space
{
    EMPTY = '.',
    WALL = 'x'
};

const int MAX_Y = 10000;
const int MAX_X = 500;
const int dy[] = {-1, 0, 1};
const int dx[] = {1, 1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_Y][MAX_X + 1];

bool dfs(int y, int x=0)
{
    map[y][x] = WALL;
    if (x == xSize - 1)
    {
        return (true);
    }

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || map[nextY][nextX] == WALL)
            continue ;

        if (dfs(nextY, nextX))
            return (true);
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    int ans = 0;
    for (int y = 0; y < ySize; ++y)
    {
        ans += dfs(y);
    }

    std::cout << ans << '\n';
    return (0);
}
