#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

const int MAX_SIZE = 20;

int dist[2];
int size, minDiff = INT_MAX;
int startY, startX;
int map[MAX_SIZE][MAX_SIZE];
int tribeIdx[MAX_SIZE][MAX_SIZE];

void    makeBorder(void)
{
    int &d1 = dist[0];
    int &d2 = dist[1];
    int y1 = startY - d2;
    int x1 = startX - d2;
    int y2 = startY - (d1 + d2);
    int x2 = startX + d1 - d2;
    int y3 = startY - d1;
    int x3 = startX + d1;

    // 1번
    {
        for (int y = 0; y < y2; ++y)
        {
            for (int x = 0; x <= x2; ++x)
            {
                tribeIdx[y][x] = 1;
            }
        }
        int minus = 1;
        for (int y = y2; y < y1; ++y)
        {
            for (int x = 0; x <= x2 - minus; ++x)
            {
                tribeIdx[y][x] = 1;
            }
            ++minus;
        }
    }

    // 2번
    {
        for (int y = 0; y <= y2; ++y)
        {
            for (int x = x2 + 1; x < size; ++x)
            {
                tribeIdx[y][x] = 2;
            }
        }
        int plus = 2;
        for (int y = y2 + 1; y <= y3; ++y)
        {
            for (int x = x2 + plus; x < size; ++x)
            {
                tribeIdx[y][x] = 2;
            }
            ++plus;
        }
    }

    // 3번
    {
        for (int y = size - 1; y >= startY; --y)
        {
            for (int x = 0; x < startX; ++x)
            {
                tribeIdx[y][x] = 3;
            }
        }
        int minus = 1;
        for (int y = startY - 1; y >= y1; --y)
        {
            for (int x = 0; x < startX - minus; ++x)
            {
                tribeIdx[y][x] = 3;
            }
            ++minus;
        }
    }

    // 4번
    {
        for (int y = size - 1; y > startY; --y)
        {
            for (int x = startX; x < size; ++x)
            {
                tribeIdx[y][x] = 4;
            }
        }
        int plus = 1;
        for (int y = startY; y > y3; --y)
        {
            for (int x = startX + plus; x < size; ++x)
            {
                tribeIdx[y][x] = 4;
            }
            ++plus;
        }
    }
}

void    calculate(void)
{
    static const int TRIBE_CNT = 5;
    static int people[TRIBE_CNT];

    memset(people, 0, sizeof(people));
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int &idx = tribeIdx[y][x];

            people[idx] += map[y][x];
            idx = 0;
        }
    }

    minDiff = std::min(
        minDiff,
        *std::max_element(people, people + TRIBE_CNT)
            - *std::min_element(people, people + TRIBE_CNT)
    );
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    startY = 2;
    while (startY < size)
    {
        startX = 1;
        while (startX < size - 1)
        {
            int &d1 = dist[0];
            int &d2 = dist[1];

            d1 = 1;
            while (startX + d1 < size)
            {
                d2 = 1;
                while (true)
                {
                    if (startX - d2 < 0 || startY - (d1 + d2) < 0)
                        break ;

                    makeBorder();
                    calculate();
                    ++d2;
                }

                ++d1;
            }

            ++startX;
        }

        ++startY;
    }

    std::cout << minDiff << '\n';
    return 0;
}