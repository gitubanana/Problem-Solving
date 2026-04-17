#include <iostream>
#include <cstdio>
#include <climits>

struct t_pos
{
    int y;
    int x;

};

template <typename T>
T   &operator>>(T &in_stream, t_pos &pos)
{
    in_stream >> pos.x >> pos.y;
    return (in_stream);
}

template <typename T>
T   &operator<<(T &out_stream, t_pos &pos)
{
    out_stream << "x : " << pos.x << ", y : " << pos.y;
    return (out_stream);
}

void    print_min_dist(t_pos &cur, t_pos &left_down, t_pos &right_up)
{
    int min_dist = INT_MAX, tmp;
    int dd[] = {left_down.x, left_down.y, right_up.x, right_up.y};

    for (int i = 0; i < 4; ++i)
    {
        if (i & 1)
            tmp = std::abs(cur.y - dd[i]);
        else
            tmp = std::abs(cur.x - dd[i]);
        min_dist = std::min(min_dist, tmp);
    }
    std::cout << min_dist << '\n';
}

int main()
{
    t_pos   cur;
    t_pos   right_up;
    t_pos   left_down = t_pos();

    std::cin >> cur >> right_up;
    print_min_dist(cur, left_down, right_up);
    return 0;
}
