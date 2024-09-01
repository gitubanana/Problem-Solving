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

const int MAX_V = 1e5 + 1;

int vCnt, up;
bool visited[MAX_V];
std::vector<t_edge> edges[MAX_V];

int prim(int start=1)
{
    int plus = -up;
    int madeEcnt = 0;
    int totalWeight = 0;
    std::priority_queue<t_edge> pq;

    pq.push({start, up});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v])
            continue ;

        visited[cur.v] = true;
        totalWeight += cur.weight + plus;
        plus += up;
        if (++madeEcnt == vCnt)
        {
            return (totalWeight);
        }

        for (const t_edge &next : edges[cur.v])
        {
            if (visited[next.v])
                continue ;

            pq.push({next.v, next.weight});
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt >> up;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    std::cout << prim() << '\n';
    return (0);
}
