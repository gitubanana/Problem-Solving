#include <iostream>
#include <climits>
#include <algorithm>

using t_func = int (*)(int, int);

inline int max(int a, int b)
{
    return std::max(a, b);
}

inline int min(int a, int b)
{
    return std::min(a, b);
}

const int MAX_SIZE = 100'000;
const int X_SIZE = 3;
const int dx[] = {-1, 0, 1};
const int dirSize = sizeof(dx) / sizeof(dx[0]);
t_func cmps[] = {
    &max,
    &min
};

int ySize;
int map[MAX_SIZE][X_SIZE];
int dp[2][MAX_SIZE][X_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < X_SIZE; ++x)
        {
            std::cin >> map[y][x];
            dp[1][y][x] = INT_MAX;
        }
    }

    for (int x = 0; x < X_SIZE; ++x)
    {
        dp[0][0][x] = dp[1][0][x] = map[0][x];
    }
    for (int y = 1; y < ySize; ++y)
    {
        for (int x = 0; x < X_SIZE; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                int prevX = x + dx[dir];
                if (!(0 <= prevX && prevX < X_SIZE))
                    continue ;

                for (int i = 0; i < 2; ++i)
                {
                    dp[i][y][x] = cmps[i](
                        dp[i][y][x],
                        dp[i][y - 1][prevX] + map[y][x]
                    );
                }
            }
        }
    }

    std::cout << *std::max_element(dp[0][ySize - 1], dp[0][ySize - 1] + X_SIZE) << ' '
              << *std::min_element(dp[1][ySize - 1], dp[1][ySize - 1] + X_SIZE) << '\n';
    return (0);
}
