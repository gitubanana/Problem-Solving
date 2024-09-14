#include <iostream>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int64_t weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

struct t_elem : public t_edge
{
    bool passed;
};

const int MAX_V = 100'001;
const int64_t INF = 1e12 + 1;

int vCnt;
bool shouldPass[MAX_V];
int64_t dists[MAX_V][2];
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start)
{
    std::priority_queue<t_elem> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v][0] = dists[v][1] = INF;
    } 
    dists[start][0] = 0;
    pq.push({start, 0, false});
    while (!pq.empty())
    {
        const t_elem cur = pq.top();
        const int64_t &curDist = dists[cur.v][cur.passed];
        pq.pop();

        if (curDist != cur.weight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            bool nextPassed = cur.passed | shouldPass[next.v];
            int64_t &cmpDist = dists[next.v][nextPassed];
            int64_t nextDist = curDist + next.weight;
            if (cmpDist <= nextDist)
                continue ;

            cmpDist = nextDist;
            pq.push({next.v, nextDist, nextPassed});
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

    int passCnt;
    int start, end;

    std::cin >> start >> end >> passCnt;
    while (passCnt--)
    {
        int v;

        std::cin >> v;
        shouldPass[v] = true;
    }

    dijkstra(start);
    std::cout << (dists[end][1] == INF ? -1 : dists[end][1]) << '\n';
    return (0);
}
