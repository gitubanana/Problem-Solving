#include <iostream>
#include <queue>

struct t_edge
{
    int from, to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 1001;
const int VIRTUAL_V = 0;

int vCnt;
int parent[MAX_V];
std::priority_queue<t_edge> pq;

int getParent(int x)
{
    int &xParent = parent[x];

    if (xParent != x)
        xParent = getParent(xParent);

    return (xParent);
}

void    group(int x, int y)
{
    parent[getParent(x)] = getParent(y);
}

int kruskal(void)
{
    for (int v = 1; v <= vCnt; ++v)
    {
        parent[v] = v;
    }

    int madeEcnt = 0;
    int totalWeight = 0;

    while (!pq.empty()
            && madeEcnt != vCnt)
    {
        const t_edge edge = pq.top();
        pq.pop();

        if (getParent(edge.from) == getParent(edge.to))
            continue ;

        ++madeEcnt;
        totalWeight += edge.weight;
        group(edge.from, edge.to);
    }
    return (totalWeight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt, virtualLinkCnt;

    std::cin >> vCnt >> eCnt >> virtualLinkCnt;
    while (virtualLinkCnt--)
    {
        int to;

        std::cin >> to;
        pq.push({VIRTUAL_V, to, 0});
    }
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        pq.push({from, to, weight});
    }


    std::cout << kruskal() << '\n';
    return (0);
}
