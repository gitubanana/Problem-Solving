#include <iostream>
#include <climits>
#include <cstring>

const int MAX = 1000;
const int COLOR_CNT = 3;

int size;
int dp[MAX][COLOR_CNT];
int house[MAX][COLOR_CNT];
const int DP_SIZE = sizeof(dp);

void    makeDp(int startColor)
{
    for (int color = 0; color < COLOR_CNT; ++color)
    {
        dp[0][color] = 1001;
    }
    dp[0][startColor] = house[0][startColor];

    for (int i = 1; i < size; ++i)
    {
        for (int color = 0; color < COLOR_CNT; ++color)
        {
            dp[i][color] = house[i][color] + std::min(
                dp[i - 1][(color + 1) % COLOR_CNT],
                dp[i - 1][(color + 2) % COLOR_CNT]
            );
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        for (int color = 0; color < COLOR_CNT; ++color)
            std::cin >> house[i][color];
    }

    int ans = INT_MAX;
    for (int startColor = 0; startColor < COLOR_CNT; ++startColor)
    {
        makeDp(startColor);

        int cmpCnt = 2;
        int cmpColor = (startColor + 1) % COLOR_CNT;
        while (cmpCnt--)
        {
            ans = std::min(ans, dp[size - 1][cmpColor]);
            cmpColor = (cmpColor + 1) % COLOR_CNT;
        }

        if (startColor != COLOR_CNT - 1)
            continue ;

        memset(dp, 0, DP_SIZE);
    }

    std::cout << ans << '\n';
    return (0);
}
