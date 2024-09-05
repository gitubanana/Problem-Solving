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
const int INF = 1e9;

int vCnt;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];
std::priority_queue<t_edge> pq;

void    dijkstra(void)
{
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int &curDist = dists[cur.v];
        pq.pop();

        if (cur.weight != curDist)
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

    int home;
    int minDist = -1;
    for (int v = 1; v <= vCnt; ++v)
    {
        int &cmpDist = dists[v];
        if (minDist < cmpDist)
        {
            minDist = cmpDist;
            home = v;
        }
    }

    std::cout << home << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    }
    for (int cnt = 0; cnt < 3; ++cnt)
    {
        int start;

        std::cin >> start;
        dists[start] = 0;
        pq.push({start, 0});
    }

    std::cin >> eCnt;
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
