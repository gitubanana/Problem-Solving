#include <iostream>
#include <algorithm>
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

const int MAX_V = 2001;
const int INF = 1e9;

int vCnt, s, g, h;
int sDists[MAX_V];
int gDists[MAX_V];
int hDists[MAX_V];
std::vector<int> dests;
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start, int dists[MAX_V])
{
    std::priority_queue<t_edge> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    }

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

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int eCnt, destCnt;

        std::cin >> vCnt >> eCnt >> destCnt;
        for (int v = 1; v <= vCnt; ++v)
        {
            edges[v].clear();
        }

        std::cin >> s >> g >> h;
        while (eCnt--)
        {
            int from, to, weight;

            std::cin >> from >> to >> weight;
            edges[from].push_back({to, weight});
            edges[to].push_back({from, weight});
        }

        dijkstra(s, sDists);
        dijkstra(g, gDists);
        dijkstra(h, hDists);

        dests.clear();
        while (destCnt--)
        {
            int dest;

            std::cin >> dest;
            dests.push_back(dest);
        }

        std::sort(dests.begin(), dests.end());
        for (const int &e : dests)
        {
            if (!(sDists[g] + gDists[h] + hDists[e] == sDists[e]
                || sDists[h] + hDists[g] + gDists[e] == sDists[e]))
                continue ;

            std::cout << e << ' ';
        }
        std::cout << '\n';
    }

    return (0);
}
