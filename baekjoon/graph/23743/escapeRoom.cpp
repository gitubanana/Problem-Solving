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

const int MAX_V = 200001;
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

    int madeCnt = 0;
    int totalWeight = 0;
    while (!pq.empty()
            && madeCnt != vCnt)
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (getParent(cur.from) == getParent(cur.to))
            continue ;

        ++madeCnt;
        totalWeight += cur.weight;
        group(cur.from, cur.to);
    }

    return (totalWeight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        t_edge edge;

        std::cin >> edge.from >> edge.to >> edge.weight;
        pq.push(edge);
    }
    for (int v = 1; v <= vCnt; ++v)
    {
        int weight;

        std::cin >> weight;
        pq.push({VIRTUAL_V, v, weight});
    }

    std::cout << kruskal() << '\n';
    return (0);
}
