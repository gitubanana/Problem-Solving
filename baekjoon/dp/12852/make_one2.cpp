#include <iostream>
#include <vector>

const int MAX = 1e6 + 1;
const int end = 1;

int dp[MAX];
int before[MAX];
bool notFound = true;

void    update_(int cur, int next)
{
    int nextCntFromCur = dp[cur] + 1;

    if (dp[next] > nextCntFromCur)
    {
        dp[next] = nextCntFromCur;
        before[next] = cur;
        if (next == end)
            notFound = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int       start;
    const int operation[] = {3, 2};

    std::cin >> start;
    for (int i = 1; i < start; ++i)
        dp[i] = MAX;

    for (int cur = start; cur >= end && notFound; --cur)
    {
        for (int i = 0; i < 2 && notFound; ++i)
        {
            if (cur % operation[i] == 0)
            {
                update_(cur, cur / operation[i]);
            }
        }
        update_(cur, cur - 1);
    }

    int cur = end;
    std::vector<int> way;

    way.push_back(end);
    while (cur != start)
    {
        way.push_back(before[cur]);
        cur = before[cur];
    }

    std::cout << dp[end] << '\n';
    for (int i = way.size() - 1; i >= 0; --i)
        std::cout << way[i] << ' ';
    std::cout << '\n';

    return (0);
}
