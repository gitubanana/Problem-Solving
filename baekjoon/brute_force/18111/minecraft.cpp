#include <iostream>
#include <set>
#include <climits>

const int   MAX = 500;

int map[MAX][MAX];
int cur_sec;
int final_sec = INT_MAX, final_height;
int min = INT_MAX, max = INT_MIN;

bool    is_possible(int y_size, int x_size, int i_got, int height_to_make)
{
    cur_sec = 0;
    for (int y = 0; y < y_size; ++y)
    {
        for (int x = 0; x < x_size; ++x)
        {
            const int   &origin_height = map[y][x];

            if (origin_height > height_to_make)
            {
                int removed_cnt = (origin_height - height_to_make);
                cur_sec += removed_cnt * 2;
                i_got += removed_cnt;
            }
            else
            {
                int added_cnt = (height_to_make - origin_height);
                cur_sec += added_cnt;
                i_got -= added_cnt;
            }
        }
    }
    return (i_got >= 0);
}

void    uniformalize_floor(int y_size, int x_size, int i_got)
{
    int &height_to_make = min;
    for (; height_to_make <= max; ++height_to_make)
    {
        if (is_possible(y_size, x_size, i_got, height_to_make))
        {
            if (cur_sec < final_sec)
            {
                final_sec = cur_sec;
                final_height = height_to_make;
            }
            else if (cur_sec == final_sec)
                final_height = std::max(final_height, height_to_make);
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int y_size, x_size;
    int i_got;

    std::cin >> y_size >> x_size >> i_got;
    for (int y = 0; y < y_size; ++y)
    {
        for (int x = 0; x < x_size; ++x)
        {
            std::cin >> map[y][x];
            min = std::min(min, map[y][x]);
            max = std::max(max, map[y][x]);
        }
    }

    uniformalize_floor(y_size, x_size, i_got);

    std::cout << final_sec << " " << final_height << '\n';

    return (0);
}
