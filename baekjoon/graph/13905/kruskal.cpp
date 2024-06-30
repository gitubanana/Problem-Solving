#include <iostream>
#include <algorithm>
#include <climits>

struct t_edge
{
    int from, to, weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 1e5;
const int MAX_E = 3 * 1e5;

int parent[MAX_V + 1];
t_edge edges[MAX_E];

inline std::istream &operator>>(std::istream &in, t_edge &edge)
{
    in >> edge.from >> edge.to >> edge.weight;
    return (in);
}

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

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;
    int start, end;

    std::cin >> vCnt >> eCnt;
    std::cin >> start >> end;
    for (int e = 0; e < eCnt; ++e)
    {
        std::cin >> edges[e];
    }

    std::sort(edges, edges + eCnt);
    for (int v = 1; v <= vCnt; ++v)
    {
        parent[v] = v;
    }

    int ans = 0;
    for (int e = 0; e < eCnt; ++e)
    {
        t_edge &edge = edges[e];

        group(edge.from, edge.to);
        if (getParent(start) == getParent(end))
        {
            ans = edge.weight;
            break ;
        }
    }

    std::cout << ans << '\n';
    return (0);
}
