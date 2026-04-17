#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

int dest_x, dest_y, ans;
int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

inline bool is_bound(int limit_y, int limit_x)
{
    return ((dest_y < limit_y) && (dest_x < limit_x));
}

void    make_z(int start_y, int start_x, int &num)
{
    int next_y, next_x;

    for (int i = 0; i < 4; ++i)
    {
        next_y = start_y + dy[i];
        next_x = start_x + dx[i];
        if (next_y == dest_y && next_x == dest_x)
            ans = num;
        ++num;
    }
}

void    recursive_z(int start_y, int start_x, int &num, int cur_size)
{
    if (cur_size == 2)
    {
        make_z(start_y, start_x, num);
        return ;
    }
    
    int half_size = cur_size / 2;

    if (is_bound(start_y + half_size, start_x + half_size))
    {
        recursive_z(start_y, start_x, num, half_size);
    }
    else if (is_bound(start_y + half_size, start_x + half_size * 2))
    {
        num += half_size * half_size;
        recursive_z(start_y, start_x + half_size, num, half_size);
    }
    else if (is_bound(start_y + half_size * 2, start_x + half_size))
    {
        num += half_size * half_size * 2;
        recursive_z(start_y + half_size, start_x, num, half_size);
    }
    else
    {
        num += half_size * half_size * 3;
        recursive_z(start_y + half_size, start_x + half_size, num, half_size);
    }
}

int main(void)
{
    int size;
    int pow_num;
    int num = 0;

    scanf(" %d %d %d", &pow_num, &dest_y, &dest_x);
    size = pow(2, pow_num);
    recursive_z(0, 0, num, size);
    printf("%d\n", ans);
    return (0);
}