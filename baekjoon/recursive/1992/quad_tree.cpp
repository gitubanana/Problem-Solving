#include <iostream>

enum e_color
{
    BLACK = '0',
    WHITE = '1'
};

const int   MAX = 64;

int  size;
char map[MAX][MAX + 1];
std::string ans;
const char colors[] = {BLACK, WHITE};
const int  colors_size = sizeof(colors) / sizeof(colors[0]);

bool    is_all(const char color, int y, int x, int size)
{
    // std::cout << "=================" << '\n';
    int end_y = y + size;
    int end_x = x + size;
    for (int cur_y = y; cur_y < end_y; ++cur_y)
    {
        for (int cur_x = x; cur_x < end_x; ++cur_x)
        {
            // std::cout << map[cur_y][cur_x] << ' ';
            if (map[cur_y][cur_x] != color)
                return (false);
        }
        // std::cout << '\n';
    }
    // std::cout << "=================" << '\n';
    return (true);
}

void    quad_tree(int y, int x, int size)
{
    int i = 0;

    // 기저 조건 -> 모두 WHITE 혹은 BLACK
    for (; i < colors_size; ++i)
    {
        if (is_all(colors[i], y, x, size))
            break ;
    }

    if (i != colors_size)
    {
        ans.push_back(colors[i]);
        return ;
    }

    ans.push_back('(');

    int half_size = size / 2;
    int half_y = y + half_size;
    int half_x = x + half_size;

    quad_tree(y, x, half_size);
    quad_tree(y, half_x, half_size);
    quad_tree(half_y, x, half_size);
    quad_tree(half_y, half_x, half_size);

    ans.push_back(')');
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> map[i];

    quad_tree(0, 0, size);

    std::cout << ans << '\n';
    return (0);
}
