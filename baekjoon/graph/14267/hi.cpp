#include <iostream>
#include <vector>

const int MAX = 100001;

int start;
int vCnt, plus;
int got[MAX];
int dp[MAX];
std::vector<int> children[MAX];

void    dfs(int cur)
{
    std::vector<int> &curChildren = children[cur];

    dp[cur] += got[start];
    for (const int &next : curChildren)
    {
        dfs(next);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int dummy;
    int eCnt, boss;

    std::cin >> vCnt >> eCnt >> dummy;
    for (int v = 2; v <= vCnt; ++v)
    {
        std::cin >> boss;
        children[boss].push_back(v);
    }

    while (eCnt--)
    {
        std::cin >> start >> plus;
        got[start] += plus;
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        start = v;
        if (got[v] > 0)
            dfs(v);
        std::cout << dp[v] << ' ';
    }
    std::cout << '\n';
    return (0);
}
