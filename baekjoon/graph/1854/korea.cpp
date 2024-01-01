#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

struct t_edge
{
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (weight > other.weight);
    }
};

typedef std::vector<t_edge> t_vec_edge;
typedef std::priority_queue<t_edge> t_pq;

const int  MAX = 1001;
const int  INF = 1e10;
t_vec_edge edges[MAX];
int        dist[MAX][100];
int        vCnt, k;

void    dijkstra(int start)
{
    t_pq pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        for (int i = 0; i < k; ++i)
            dist[v][i] = INF;
    }

    dist[1][0] = 0;
    pq.push({1, 0});
    while (!pq.empty())
    {
        const int cur = pq.top().to;
        const int curDist = pq.top().weight;

        pq.pop();
        if (dist[cur][k - 1] < curDist)
            continue ;

        for (const t_edge &edge : edges[cur])
        {
            const int &next = edge.to;
            const int &weight = edge.weight;
            int nextDist = curDist + weight;

            if (dist[next][k - 1] <= nextDist)
                continue ;

            pq.push({next, nextDist});
            dist[next][k - 1] = nextDist;
            std::sort(dist[next], dist[next] + k);
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int eCnt;
    int from, to, weight;

    std::cin >> vCnt >> eCnt >> k;
    while (eCnt)
    {
        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        --eCnt;
    }

    dijkstra(1);

    for (int v = 1; v <= vCnt; ++v)
    {
        if (dist[v][k - 1] != INF)
            std::cout << dist[v][k - 1];
        else
            std::cout << "-1";
        std::cout << '\n';
    }

    return (0);
}