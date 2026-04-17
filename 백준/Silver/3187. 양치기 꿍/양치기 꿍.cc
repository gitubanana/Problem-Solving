#include <iostream>

const int       MAX = 250;

char    map[MAX][MAX + 1];
int             y_size, x_size;
//up, down, right, left
int     dy[] = {-1, 1, 0, 0};
int     dx[] = {0, 0, 1, -1};

void    dfs(int y, int x, int &cur_sheep, int &cur_wolf)
{
        if (!(0 <= y && y < y_size)
                || !(0 <= x && x < x_size)
                || map[y][x] == '#')
                return ;
        cur_sheep += (map[y][x] == 'k');
        cur_wolf += (map[y][x] == 'v');
        map[y][x] = '#';
        for (int i = 0; i < 4; i++)
                dfs(y + dy[i], x + dx[i], cur_sheep, cur_wolf);
}

int     main(void)
{
        int     y, x;
        int     cur_sheep, cur_wolf;
        int     total_sheep, total_wolf;

        std::cin >> y_size >> x_size;
        for (y = 0; y < y_size; y++)
                for (x = 0; x < x_size; x++)
                        std::cin >> map[y][x];
        total_sheep = total_wolf = 0;
        for (y = 0; y < y_size; y++)
        {
                for (x = 0; x < x_size; x++)
                {
                        if (map[y][x] != '#')
                        {
                                cur_sheep = cur_wolf = 0;
                                dfs(y, x, cur_sheep, cur_wolf);
                                if (cur_sheep > cur_wolf)
                                        total_sheep += cur_sheep;
                                else
                                        total_wolf += cur_wolf;
                        }
                }
        }
        std::cout << total_sheep << " " << total_wolf;
        return (0);
}