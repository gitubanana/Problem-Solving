#include <iostream>
#include <queue>
#include <vector>

struct t_edge
{
    int v;
    int weight;
};

struct t_dijk
{
    int v;
    int dist;
    int goTo;

    inline bool operator<(const t_dijk &other) const
    {
        return (this->dist > other.dist);
    }
};

const int MAX_V = 201;
const int INF = 1e9 + 1;

int vCnt;
int dist[MAX_V];
int goTo[MAX_V][MAX_V];
std::vector<t_edge> edges[MAX_V];

void    dijkstra(int start)
{
    std::priority_queue<t_dijk> pq;

    dist[start] = 0;
    for (const t_edge &next : edges[start])
    {
        dist[next.v] = next.weight;
        pq.push({next.v, next.weight, next.v});
    }

    while (!pq.empty())
    {
        const t_dijk cur = pq.top();
        pq.pop();

        if (cur.dist != dist[cur.v])
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int &oldDist = dist[next.v];
            int newDist = cur.dist + next.weight;
            if (oldDist > newDist)
            {
                oldDist = newDist;
                goTo[start][next.v] = cur.goTo;
                pq.push({next.v, newDist, cur.goTo});
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    int from, to, weight;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
        goTo[from][to] = to;
        goTo[to][from] = from;
    }

    for (int from = 1; from <= vCnt; ++from)
    {
        for (int v = 1; v <= vCnt; ++v)
        {
            dist[v] = INF;
        }
        dijkstra(from);
    }

    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            if (goTo[from][to] == 0)
                std::cout << '-';
            else
                std::cout << goTo[from][to];

            std::cout << ' ';
        }
        std::cout << '\n';
    }
    return (0);
}
