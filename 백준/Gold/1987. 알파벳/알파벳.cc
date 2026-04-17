#include <iostream>
#include <string>

const int   MAX = 20;

char    map[MAX][MAX + 1];
int     have_been[26];
int     y_size, x_size;
int     max;
// up, down, left, right
int     dy[] = {-1, 1, 0, 0};
int     dx[] = {0, 0, -1, 1};

void    find_max_move(int y, int x, int cnt)
{
    int i;
    int next_y, next_x;

    max = std::max(max, cnt);
    for (i = 0; i < 4; ++i)
    {
        next_y = y + dy[i];
        next_x = x + dx[i];
        if (!(0 <= next_y && next_y < y_size)
            || !(0 <= next_x && next_x < x_size)
            || have_been[map[next_y][next_x] - 65])
            continue ;
        have_been[map[next_y][next_x] - 65] = 1;
        find_max_move(next_y, next_x, cnt + 1);
        have_been[map[next_y][next_x] - 65] = 0;
    }
}

int main()
{
    int y;

    scanf(" %d %d", &y_size, &x_size);
    for (y = 0; y < y_size; ++y)
        scanf(" %s", map[y]);
    have_been[map[0][0] - 65] = 1;
    find_max_move(0, 0, 1);
    printf("%d\n", max);
    return (0);
}