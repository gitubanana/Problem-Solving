#include <iostream>
#include <queue>
#include <vector>

struct t_edge
{
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int INF = 1e9;
const int MAX = 1001;

int ans;
int vCnt;
int dists[MAX];
std::vector<t_edge> edges[MAX];

int dijkstra(int start, int dest)
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

                if (dists[next.to] > nextDist)
                {
                    dists[next.to] = nextDist;
                    pq.push({next.to, nextDist});
                }
            }
        }
        pq.pop();
    }
    return (dists[dest]);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int from;
    int eCnt, partyDest;
    t_edge edge;

    std::cin >> vCnt >> eCnt >> partyDest;
    while (eCnt--)
    {
        std::cin >> from >> edge.to >> edge.weight;
        edges[from].push_back(edge);
    }

    for (int start = 1; start <= vCnt; ++start)
    {
        if (start == partyDest)
            continue ;

        int time_ = dijkstra(start, partyDest) + dijkstra(partyDest, start);
        ans = std::max(ans, time_);
    }

    std::cout << ans << '\n';
    return (0);
}
