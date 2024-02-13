#include <iostream>

enum e_space
{
    EMPTY = 0,
    WALL
};

const int MAX = 16;

int map[MAX][MAX];
int dy[] = {1, 0, 1};
int dx[] = {1, 1, 0};
int dirSize[] = {3, 2, 2};
int step[] = {1, 1, 2};
int size, ans;

inline bool noPipe(int y, int x, int dir)
{
    if (dir == 0
        && (map[y - 1][x] == WALL || map[y][x - 1] == WALL))
    {
        return (true);
    }
    return (map[y][x] == WALL);
}

void count_pipe(int y, int x, int type)
{
    int dir = 0;
    for (int i = 0; i < dirSize[type]; ++i, dir += step[type])
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size)
            || noPipe(nextY, nextX, dir))
            continue ;

        ans += (nextY == size - 1 && nextX == size - 1);
        count_pipe(nextY, nextX, dir);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> map[y][x];
    }

    count_pipe(0, 1, 1);

    std::cout << ans << '\n';
    return (0);
}
