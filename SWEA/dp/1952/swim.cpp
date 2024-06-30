#include <iostream>
#include <cstring>

const int COST_CNT = 4;
const int MONTH_CNT = 12;
const int dx[] = {1, 1, 3};
const int wayCnt = sizeof(dx) / sizeof(dx[0]);

int useDay[MONTH_CNT];
uint32_t cost[COST_CNT];
uint32_t dp[MONTH_CNT];

uint32_t    findMinCost(int cur=0)
{
    if (cur >= MONTH_CNT)
        return (0);

    uint32_t &curDp = dp[cur];
    int      &curUseDay = useDay[cur];

    if (curDp != UINT32_MAX)
        return (curDp);

    if (curUseDay == 0)
        return (curDp = findMinCost(cur + 1));

    for (int i = 0; i < wayCnt; ++i)
    {
        curDp = std::min(
            curDp,
            cost[i] * (i == 0 ? curUseDay : 1)
                + findMinCost(cur + dx[i])
        );
    }
    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        for (int i = 0; i < COST_CNT; ++i)
        {
            std::cin >> cost[i];
        }

        for (int i = 0; i < MONTH_CNT; ++i)
        {
            std::cin >> useDay[i];
        }

        memset(dp, -1, sizeof(dp));
        uint32_t ans = std::min(
            cost[COST_CNT - 1],
            findMinCost()
        );
        std::cout << "#" << t << ' ' << ans << '\n';
    }
    return (0);
}
