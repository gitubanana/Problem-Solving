#include <iostream>
#include <climits>
#include <vector>
#include <queue>

enum e_status
{
    SAFE = 0,
    DANGER,
    ZOMBIE
};

struct t_edge
{
    int v;
    int64_t weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 1e5 + 1;

int vCnt, zombieDist;
int cost[2];
int status[MAX_V];
int64_t minCost[MAX_V];
std::vector<int> edges[MAX_V];

void    bfs(std::queue<int> &q)
{
    while (!q.empty() && zombieDist--)
    {
        int qSize = q.size();

        while (qSize--)
        {
            const int cur = q.front();
            q.pop();

            for (const int &next : edges[cur])
            {
                int &nextStatus = status[next];
                if (nextStatus != SAFE)
                    continue ;

                nextStatus = DANGER;
                q.push(next);
            }
        }
    }
}

int64_t bfs01(int start, int end)
{
    int64_t endCost = LONG_LONG_MAX;
    std::priority_queue<t_edge> pq;

    minCost[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (cur.weight > minCost[cur.v]
            || cur.weight >= endCost)
            continue ;

        for (const int &next : edges[cur.v])
        {
            const int &nextStatus = status[next];
            if (nextStatus == ZOMBIE)
                continue ;

            if (next == end)
            {
                endCost = std::min(endCost, cur.weight);
                continue ;
            }

            int64_t &cmpCost = minCost[next];
            int64_t nextCost = cur.weight + cost[nextStatus];
            if (!(cmpCost == 0 || cmpCost > nextCost))
                continue ;

            cmpCost = nextCost;
            pq.push({next, nextCost});
        }
    }

    return (endCost);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt, zombieCnt;
    std::queue<int> q;

    std::cin >> vCnt >> eCnt >> zombieCnt >> zombieDist;
    for (int i = 0; i < 2; ++i)
    {
        std::cin >> cost[i];
    }
    for (int i = 0; i < zombieCnt; ++i)
    {
        int v;

        std::cin >> v;
        status[v] = ZOMBIE;
        q.push(v);
    }
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    bfs(q);
    std::cout << bfs01(1, vCnt) << '\n';
    return (0);
}
