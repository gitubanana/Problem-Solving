#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

struct t_bridge
{
    int from, to;
    int weight;

    inline bool operator<(const t_bridge &other) const
    {
        return (this->weight < other.weight);
    }
};

struct t_edge
{
    int v;
    int weight;
};

const int MAX_V = 1000;

int vCnt, maxWeight;
int parents[MAX_V];
bool visited[MAX_V];
std::vector<t_bridge> bridges;
std::vector<t_edge> mstEdge[MAX_V];

int getParent(int x)
{
    int &xParent = parents[x];
    if (xParent != x)
    {
        xParent = getParent(xParent);
    }
    return (xParent);
}

inline void    group(int y, int x)
{
    parents[getParent(y)] = parents[getParent(x)];
}

int64_t kruskal(void)
{
    int madeEcnt = 0;
    int eLimit = vCnt - 1;
    int64_t totalWeight = 0;

    std::sort(bridges.begin(), bridges.end());
    for (int v = 0; v < vCnt; ++v)
    {
        parents[v] = v;
    }
    for (const t_bridge &b : bridges)
    {
        if (getParent(b.from) != getParent(b.to))
        {
            ++madeEcnt;
            totalWeight += b.weight;
            group(b.from, b.to);
            mstEdge[b.from].push_back({b.to, b.weight});
            mstEdge[b.to].push_back({b.from, b.weight});
        }

        if (madeEcnt == eLimit)
            break ;
    }

    return (totalWeight);
}

int64_t dfs(int cur=0)
{
    int max1 = 0, max2 = 0;

    visited[cur] = true;
    for (const t_edge &next : mstEdge[cur])
    {
        if (visited[next.v] == true)
            continue ;

        int64_t nextDfs = dfs(next.v) + next.weight;
        if (max1 < nextDfs)
            max2 = max1, max1 = nextDfs;
        else if (max2 < nextDfs)
            max2 = nextDfs;
    }

    maxWeight = std::max(maxWeight, max1 + max2);
    return (max1);
}


int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    bridges.reserve(eCnt);
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        bridges.push_back({from, to, weight});
    }

    int64_t mstWeight = kruskal();
    dfs();

    std::cout << mstWeight << '\n';
    std::cout << maxWeight << '\n';
    return (0);
}
