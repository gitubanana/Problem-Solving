#include <iostream>

enum e_space
{
    EMPTY = 'O',
    WALL = 'X',
    ME = 'I',
    PERSON = 'P'
};

const int   MAX = 600;

char map[MAX][MAX + 1];
int y_size, x_size, max;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int dir_size = sizeof(dy) / sizeof(dy[0]);

void    dfs(int y, int x)
{
    if (map[y][x] == PERSON)
        ++max;

    map[y][x] = WALL;
    for (int i = 0; i < dir_size; ++i)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if (!(0 <= next_y && next_y < y_size)
            || !(0 <= next_x && next_x < x_size)
            || map[next_y][next_x] == WALL)
            continue ;
        dfs(next_y, next_x);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int y, x;
    int start_y = 0, start_x = 0;

    std::cin >> y_size >> x_size;
    for (y = 0; y < y_size; ++y)
    {
        std::cin >> map[y];
        if (start_y)
            continue ;

        for (x = 0; map[y][x]; ++x)
        {
            if (map[y][x] == ME)
                start_y = y, start_x = x;
        }
    }

    dfs(start_y, start_x);

    if (max == 0)
        std::cout << "TT";
    else
        std::cout << max;

    std::cout << '\n';
    return (0);
}
