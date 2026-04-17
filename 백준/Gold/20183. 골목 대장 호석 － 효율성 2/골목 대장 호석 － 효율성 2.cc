#include <iostream>
#include <climits>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;
};

struct t_elem
{
    int64_t takeMoney;
    int v;

    inline bool operator<(const t_elem &other) const
    {
        return (this->takeMoney > other.takeMoney);
    }
};

const int MAX_V = 1e5 + 1;
const int MAX_TAKE = 1e9;

int vCnt, start, end;
int64_t moneyLimit;
int64_t money[MAX_V];
std::vector<t_edge> edges[MAX_V];

bool canEndure(int maxTake)
{
    std::priority_queue<t_elem> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        money[v] = LONG_LONG_MAX;
    }

    money[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        const t_elem cur = pq.top();
        const int64_t &curTake = money[cur.v];
        pq.pop();

        if (cur.takeMoney > curTake)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int64_t &cmpTake = money[next.v];
            int64_t nextTake = curTake + next.weight;
            if (cmpTake <= nextTake
                || moneyLimit < nextTake
                || maxTake < next.weight)
                continue ;

            if (next.v == end)
                return (true);

            cmpTake = nextTake;
            pq.push({nextTake, next.v});
        }
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt >> start >> end >> moneyLimit;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    int ans = INT_MAX;
    int left = 1;
    int right = MAX_TAKE;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (canEndure(mid))
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return (0);
}
