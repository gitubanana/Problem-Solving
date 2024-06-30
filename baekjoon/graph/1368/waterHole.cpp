#include <iostream>
#include <queue>
#include <numeric>
#include <algorithm>

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int MAX_V = 301;
const int VIRTUAL = 0;

int vCnt;
bool visited[MAX_V];
int pipeCost[MAX_V][MAX_V];

int prim(int start=VIRTUAL)
{
    int totalWeight = 0;
    std::priority_queue<t_edge> pq;

    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v])
            continue ;

        visited[cur.v] = true;
        totalWeight += cur.weight;
        for (int next = 1; next <= vCnt; ++next)
        {
            if (visited[next])
                continue ;

            pq.push({next, pipeCost[cur.v][next]});
        }
    }

    return (totalWeight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cin >> pipeCost[VIRTUAL][v];
    }
    for (int from = 1; from <= vCnt; ++from)
    {
        for (int to = 1; to <= vCnt; ++to)
        {
            std::cin >> pipeCost[from][to];
        }
    }

    std::cout << prim() << '\n';
    return (0);
}
