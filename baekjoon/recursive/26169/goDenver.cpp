#include <iostream>

enum e_space
{
    WALL = -1,
    EMPTY,
    APPLE
};

const int SIZE = 5;

int map[SIZE][SIZE];
bool visited[SIZE][SIZE];

bool back_tracking(int y, int x, int depth=0, int curApple=0)
{
    static const int dy[] = {-1, 1, 0, 0};
    static const int dx[] = {0, 0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    if (depth <= 3)
    {
        if (curApple >= 2)
            return (true);
    }
    else
    {
        return (false);
    }

    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < SIZE)
            || !(0 <= nextX && nextX < SIZE)
            || map[nextY][nextX] == WALL
            || visited[nextY][nextX])
            continue ;

        if (back_tracking(nextY, nextX, depth + 1, curApple + (map[nextY][nextX] == APPLE)))
            return (true);
    }
    visited[y][x] = false;
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int startY, startX;

    std::cin >> startY >> startX;
    std::cout << back_tracking(startY, startX) << '\n';
    return (0);
}
