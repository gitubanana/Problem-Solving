#include <iostream>
#include <cstdio>

const int       MAX = 1000;

int     y_size, x_size;
int     map[MAX][MAX];
// up, down, right, left
int     dy[] = {-1, 1, 0, 0};
int     dx[] = {0, 0, 1, -1};

void    dfs(int y, int x, int comp)
{
        int     next_y, next_x;

        map[y][x] = 0;
        for (int i = 0; i < 4; ++i)
        {
                next_y = y + dy[i];
                next_x = x + dx[i];
                if (!(0 <= next_y && next_y < y_size)
                        || !(0 <= next_x && next_x < x_size)
                        || map[next_y][next_x] < comp)
                        continue ;
                dfs(next_y, next_x, comp);
        }
}

int     main(void)
{
        int     y, x;
        int     r, g, b, avg, comp;

        scanf(" %d %d", &y_size, &x_size);
        for (y = 0; y < y_size; ++y)
        {
                for (x = 0; x < x_size; ++x)
                {
                        scanf(" %d %d %d", &r, &g, &b);
                        avg = (r + g + b) / 3;
                        map[y][x] = avg;
                }
        }
        scanf(" %d", &comp);

        int     cnt = 0;
        for (y = 0; y < y_size; ++y)
                for (x = 0; x < x_size; ++x)
                        if (map[y][x] >= comp)
                                dfs(y, x, comp), ++cnt;
        printf("%d\n", cnt);
        return (0);
}