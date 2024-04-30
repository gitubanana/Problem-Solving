#include <iostream>
#include <algorithm>
#include <climits>

enum e_idx
{
    MAX,
    MIN
};

const int X_SIZE = 3;
const int MAX_Y = 100001;
const int dx[] = {-1, 0, 1};
const int dirSize = sizeof(dx) / sizeof(dx[0]);

int ySize;
int prev[2][X_SIZE];
int dp[2][X_SIZE];
int score[MAX_Y][X_SIZE];

inline bool isBound(int x)
{
    return (0 <= x && x < X_SIZE);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize;
    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < X_SIZE; ++x)
            std::cin >> score[y][x];
    }

    for (int x = 0; x < X_SIZE; ++x)
    {
        dp[MAX][x] = dp[MIN][x] = score[1][x];
    }
    for (int y = 1; y < ySize; ++y)
    {
        int nextY = y + 1;

        for (int i = MAX; i <= MIN; ++i)
        {
            for (int x = 0; x < X_SIZE; ++x)
            {
                prev[i][x] = dp[i][x];
                dp[i][x] = (i == MAX ? 0 : INT_MAX);
            }
        }

        for (int x = 0; x < X_SIZE; ++x)
        {
            for (int dir = 0; dir < dirSize; ++dir)
            {
                int nextX = x + dx[dir];

                if (!isBound(nextX))
                    continue ;

                dp[MAX][nextX] = std::max(
                    dp[MAX][nextX],
                    prev[MAX][x] + score[nextY][nextX]
                );

                dp[MIN][nextX] = std::min(
                    dp[MIN][nextX],
                    prev[MIN][x] + score[nextY][nextX]
                );
            }
        }
    }
    std::cout << *std::max_element(dp[MAX], dp[MAX] + X_SIZE) << ' ';
    std::cout << *std::min_element(dp[MIN], dp[MIN] + X_SIZE) << '\n';
    return (0);
}
