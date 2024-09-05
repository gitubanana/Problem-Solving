#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

struct t_elem : public t_edge
{
    int parent;
};

const int MAX_V = 1001;
const int INF = 1e8;

int vCnt;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start=1)
{
    std::priority_queue<t_elem> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    }

    dists[start] = 0;
    pq.push({start, 0, 0});
    std::cout << vCnt - 1 << '\n';
    while (!pq.empty())
    {
        const t_elem cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.weight != curDist)
            continue ;

        if (cur.parent != 0)
            std::cout << cur.parent << ' ' << cur.v << '\n';

        for (const t_edge &next : edges[cur.v])
        {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.weight;
            if (cmpDist <= nextDist)
                continue ;

            cmpDist = nextDist;
            pq.push({next.v, nextDist, cur.v});
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    dijkstra();
    return (0);
}
