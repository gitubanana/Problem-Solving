#include <iostream>

const int MAX = 101;

int map[MAX][MAX];
int size;
int series;

bool isPossible(int y, int x, int dy, int dx)
{
    while (y < size && x < size)
    {
        int curHeight = map[y][x];
        int curSeries = 1;

        while (true)
        {
            y += dy;
            x += dx;
            if (curHeight != map[y][x])
                break ;
            ++curSeries;
        }

        int nextHeight = map[y][x];
        if (nextHeight == 0)
            break ;
        else
        {
            int diff = nextHeight - curHeight;
            if (diff == 1)
            {
                if (curSeries < series)
                    return (false);
            }
            else if (diff == -1)
            {
                curSeries = series;
                while (map[y][x] == nextHeight && --curSeries)
                {
                    y += dy;
                    x += dx;
                }
                if (curSeries > 0)
                    return (false);

                int nextY = y + dy;
                int nextX = x + dx;

                if (map[nextY][nextX] == 0)
                    return (true);

                if (map[nextY][nextX] == nextHeight)
                {
                    y += dy;
                    x += dx;
                }
                else if (map[nextY][nextX] > nextHeight)
                {
                    return (false);
                }
            }
            else
                return (false);
        }
    }
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> series;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int ans = 0;

    for (int y = 0; y < size; ++y)
    {
        if (isPossible(y, 0, 0, 1))
        {
            ++ans;
        }
    }

    for (int x = 0; x < size; ++x)
    {
        if (isPossible(0, x, 1, 0))
        {
            ++ans;
        }
    }
    std::cout << ans << '\n';
    return (0);
}
