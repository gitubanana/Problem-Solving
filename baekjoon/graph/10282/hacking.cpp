#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct t_edge
{
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int V_MAX = 10001;
const int INF = 1e9 + 1;

int vCnt, start;
int dists[V_MAX];
std::vector<t_edge> edges[V_MAX];

void    dijkstra(void)
{
    for (int v = 1; v <= vCnt; ++v)
        dists[v] = INF;

    std::priority_queue<t_edge> pq;

    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();

        if (dists[cur.to] == cur.weight)
        {
            for (const t_edge &next : edges[cur.to])
            {
                int nextDist = dists[cur.to] + next.weight;

                if (nextDist < dists[next.to])
                {
                    dists[next.to] = nextDist;
                    pq.push({next.to, nextDist});
                }
            }
        }
        pq.pop();
    }

    int time_ = 0;
    int hackedCnt = 0;

    for (int v = 1; v <= vCnt; ++v)
    {
        if (dists[v] != INF)
        {
            ++hackedCnt;
            time_ = std::max(time_, dists[v]);
        }
    }

    std::cout << hackedCnt << ' ' << time_ << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int from, eCnt;
    t_edge edge;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt >> eCnt >> start;
        for (int v = 1; v <= vCnt; ++v)
            edges[v].clear();
        while (eCnt--)
        {
            std::cin >> edge.to >> from >> edge.weight;
            edges[from].push_back(edge);
        }

        dijkstra();
    }
    return (0);
}
