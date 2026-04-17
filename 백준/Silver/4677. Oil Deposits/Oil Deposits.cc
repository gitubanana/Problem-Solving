#include <iostream>
#include <cstdio>

const int       MAX = 100;
const char      OIL = '@';
const char      NO = '*';

int             y_size, x_size;
char    map[MAX][MAX + 1];
// up, down, left, right, up + left, up + right, down + left, down + left
int     dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int     dx[] = {0, 0, 1, -1, 1, -1, 1, -1};

void    dfs(int y, int x)
{
        int     next_y, next_x;

        map[y][x] = NO;
        for (int i = 0; i < 8; ++i)
        {
                next_y = y + dy[i];
                next_x = x + dx[i];
                if (!(0 <= next_y && next_y < y_size)
                        || !(0 <= next_x && next_x < x_size)
                        || map[next_y][next_x] == NO)
                        continue ;
                dfs(next_y, next_x);
        }
}

int     main(void)
{
        int     cnt;
        int     y, x;

        while (true)
        {
                scanf(" %d %d", &y_size, &x_size);
                if (y_size == 0)
                        break ;
                for (y = 0; y < y_size; ++y)
                        scanf(" %s", map[y]);
                cnt = 0;
                for (y = 0; y < y_size; ++y)
                        for (x = 0; x < x_size; ++x)
                                if (map[y][x] == OIL)
                                        dfs(y, x), ++cnt;
                printf("%d\n", cnt);
        }
        return (0);
}