#include <iostream>
#include <unordered_set>
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

const int MAX_V = 10001;
const int INF = 1e8 + 1;
const int STORE_CNT = 2;

int vCnt;
int canGoDist[STORE_CNT];
int dists[STORE_CNT][MAX_V];
std::vector<t_edge> edges[MAX_V];

void    djikstra(std::vector<int> &start, int *dist)
{
    std::priority_queue<t_edge> pq;

    for (const int &v : start)
    {
        dist[v] = 0;
        pq.push({v, 0});
    }
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int &curDist = dist[cur.v];
        pq.pop();

        if (curDist != cur.weight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int &cmpDist = dist[next.v];
            int nextDist = cur.weight + next.weight;

            if (cmpDist > nextDist)
            {
                cmpDist = nextDist;
                pq.push({next.v, nextDist});
            }
        }
    }
}

void    printBestDist(void)
{
    int bestDist = INF * 2;

    for (int v = 1; v <= vCnt; ++v)
    {
        int cmpDist = 0;

        for (int i = 0; i < STORE_CNT; ++i)
        {
            const int &checkDist = dists[i][v];

            if (checkDist == 0 || checkDist > canGoDist[i])
            {
                cmpDist = 0;
                break ;
            }

            cmpDist += checkDist;
        }

        if (cmpDist == 0)
            continue ;

        bestDist = std::min(bestDist, cmpDist);
    }

    std::cout << (bestDist == INF * 2 ? -1 : bestDist) << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        for (int i = 0; i < STORE_CNT; ++i)
        {
            dists[i][v] = INF;
        }
    }
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    for (int i = 0; i < STORE_CNT; ++i)
    {
        int cnt;
        std::vector<int> start;

        std::cin >> cnt >> canGoDist[i];
        while (cnt--)
        {
            int v;

            std::cin >> v;
            start.push_back(v);
        }

        djikstra(start, reinterpret_cast<int *>(dists + i));
    }

    printBestDist();
    return (0);
}
