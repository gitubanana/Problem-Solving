#include <iostream>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 100'001;
const int INF = 1e9 + 1;

int vCnt;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

inline void initDist(void)
{
    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    } 
}

void    dijkstra(int start)
{
    std::priority_queue<t_edge> pq;

    dists[start] = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.weight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.weight;
            if (cmpDist <= nextDist)
                continue ;

            cmpDist = nextDist;
            pq.push({next.v, nextDist});
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
    }

    int start, by, end;
    std::cin >> start >> by >> end;

    initDist();
    dijkstra(start);
    int byDist = dists[by];

    if (byDist == INF)
    {
        byDist = -1;
    }
    else
    {
        initDist();
        dijkstra(by);

        byDist = (dists[end] == INF ? -1 : byDist + dists[end]);
    }

    std::cout << byDist << ' ';

    initDist();
    dists[by] = 0;
    dijkstra(start);

    std::cout << (dists[end] >= INF ? -1 : dists[end]) << '\n';
    return (0);
}
