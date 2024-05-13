#include <iostream>

const int MAP_SIZE = 9;
const int RANGE_SIZE = MAP_SIZE / 3;
const int EMPTY = 0;

int map[MAP_SIZE][MAP_SIZE + 1];

inline int getRangeStart(int pos)
{
    return (pos / RANGE_SIZE * 3);
}

inline bool isValid(int y, int x, int num)
{
    for (int checkY = 0; checkY < MAP_SIZE; ++checkY)
    {
        if (map[checkY][x] == num)
            return (false);
    }

    for (int checkX = 0; checkX < MAP_SIZE; ++checkX)
    {
        if (map[y][checkX] == num)
            return (false);
    }

    int startY = getRangeStart(y);
    int startX = getRangeStart(x);
    int endY = startY + RANGE_SIZE;
    int endX = startX + RANGE_SIZE;
    for (int checkY = startY; checkY < endY; ++checkY)
    {
        for (int checkX = startX; checkX < endX; ++checkX)
        {
            if (map[checkY][checkX] == num)
                return (false);
        }
    }

    return (true);
}

void    back_tracking(int y=0, int x=0)
{
    while (true)
    {
        if (x >= MAP_SIZE)
        {
            ++y;
            x = 0;
        }
        if (y >= MAP_SIZE)
            break ;

        if (map[y][x] == EMPTY)
        {
            for (char num = 1; num <= 9; ++num)
            {
                int &curSpace = map[y][x];

                if (!isValid(y, x, num))
                    continue ;

                curSpace = num;
                back_tracking(y, x + 1);
                curSpace = EMPTY;
            }
            return ;
        }
        ++x;
    }

    for (int y = 0; y < MAP_SIZE; ++y)
    {
        for (int x = 0; x < MAP_SIZE; ++x)
        {
            std::cout << map[y][x] << ' ';
        }
        std::cout << '\n';
    }
    exit(0);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int y = 0; y < MAP_SIZE; ++y)
    {
        for (int x = 0; x < MAP_SIZE; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    back_tracking();
    return (0);
}
