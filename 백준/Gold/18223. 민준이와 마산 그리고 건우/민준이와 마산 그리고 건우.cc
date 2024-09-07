#include <iostream>
#include <vector>
#include <queue>
#define START 1
#define END vCnt

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 5001;
const int INF = 1e9;

int vCnt;
int dists[MAX_V];
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start)
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

    int eCnt, gunwoo;
    const char *msg[] = {"SAVE HIM", "GOOD BYE"};

    std::cin >> vCnt >> eCnt >> gunwoo;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    dijkstra(START);
    int sToE = dists[END];

    dijkstra(gunwoo);

    std::cout << msg[sToE < dists[START] + dists[END]] << '\n';
    return (0);
}
