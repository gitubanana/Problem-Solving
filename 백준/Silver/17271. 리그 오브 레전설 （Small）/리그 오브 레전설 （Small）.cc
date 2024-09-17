#include <iostream>
#include <cstring>

const int MAX_TIME = 10'000;
const int DIVISOR = 1'000'000'007;

int endTime, bTime;
int dp[MAX_TIME][2];

int dfs(int curTime=0, int prevSkill=0)
{
    if (curTime > endTime)
        return (0);

    if (curTime == endTime)
        return (1);

    int &curDp = dp[curTime][prevSkill];
    if (curDp != -1)
        return (curDp);

    curDp = 0;
    curDp += dfs(curTime + 1, 0);
    curDp %= DIVISOR;

    curDp += dfs(curTime + bTime, 1);
    curDp %= DIVISOR;

    return (curDp);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> endTime >> bTime;

    memset(dp, -1, sizeof(dp));
    std::cout << dfs() << '\n';
    return (0);
}
