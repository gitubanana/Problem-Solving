#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>

struct t_pos
{
    double y, x;
};

struct t_edge
{
    double weight;
    int from, to;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight < other.weight);
    }
};

const int MAX_V = 1001;

int vCnt;
int parents[MAX_V];
t_pos pos[MAX_V];

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
    parents[getParent(y)] = getParent(x);
}

inline double getDist(int from, int to)
{
    t_pos &a = pos[from];
    t_pos &b = pos[to];

    return (std::sqrt(std::pow(std::abs(a.y - b.y), 2)
                        + std::pow(std::abs(a.x - b.x), 2)));
}

double kruskal(void)
{
    std::vector<t_edge> sorted;

    sorted.reserve(vCnt * (vCnt + 1) / 2);
    for (int from = 1; from < vCnt; ++from)
    {
        for (int to = from + 1; to <= vCnt; ++to)
        {
            sorted.push_back({getDist(from, to), from, to});
        }
    }
    std::sort(sorted.begin(), sorted.end());

    double totalWeight = 0;
    for (const t_edge &cur : sorted)
    {
        if (getParent(cur.from) != getParent(cur.to))
        {
            group(cur.from, cur.to);
            totalWeight += cur.weight;
        }
    }

    return (totalWeight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        parents[v] = v;
        std::cin >> pos[v].y >> pos[v].x;
    }

    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        if (getParent(from) != getParent(to))
        {
            group(from, to);
        }
    }

    std::cout << std::fixed << std::setprecision(2) << kruskal() << '\n';
    return (0);
}
