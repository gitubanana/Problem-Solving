#include <iostream>

enum e_space
{
    WALL = 0,
    EMPTY
};

const int MAX_SIZE = 300;

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];

bool dfs(int y=0, int x=0)
{
    static const int dy[] = {1, 0};
    static const int dx[] = {0, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    if (y == ySize - 1 && x == xSize - 1)
    {
        return true;
    }

    map[y][x] = WALL;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize)
            || map[nextY][nextX] == WALL)
        {
            continue;
        }

        if (dfs(nextY, nextX))
            return true;
    }
    return false;
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    const char *msg[] = {"No", "Yes"};

    std::cin >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    std::cout << msg[dfs()] << '\n';
    return 0;
}
