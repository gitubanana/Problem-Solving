#include <iostream>
#include <queue>
#include <algorithm>

struct t_edge
{
    int v;
    long long weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 1e5 + 1;
const int64_t INF = 1e10;

int64_t dists[MAX_V];
std::vector<t_edge> edges[MAX_V];
std::priority_queue<t_edge> pq;

void    dijkstra(void)
{
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int64_t &curDist = dists[cur.v];
        pq.pop();

        if (curDist != cur.weight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int64_t &cmpDist = dists[next.v];
            int64_t nextDist = curDist + next.weight;

            if (cmpDist > nextDist)
            {
                cmpDist = nextDist;
                pq.push({next.v, nextDist});
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt, interviewCnt;

    std::cin >> vCnt >> eCnt >> interviewCnt;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[to].push_back({from, weight});
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        dists[v] = INF;
    }
    while (interviewCnt--)
    {
        int start;

        std::cin >> start;
        dists[start] = 0;
        pq.push({start, 0});
    }

    dijkstra();

    int64_t *maxDist = std::max_element(
        dists + 1,
        dists + 1 + vCnt
    );

    std::cout << maxDist - dists << '\n';
    std::cout << *maxDist << '\n';
    return (0);
}
