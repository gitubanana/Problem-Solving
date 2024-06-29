#include <iostream>
#include <climits>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight < other.weight);
    }
};

const int MAX_V = 10000;

int weight[MAX_V + 1];
std::vector<t_edge> edges[MAX_V + 1];

int dijkstra(int start, int end)
{
    std::priority_queue<t_edge> pq;
    int &endWeight = weight[end];

    weight[start] = INT_MAX;
    pq.push({start, INT_MAX});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int &curWeight = weight[cur.v];
        pq.pop();

        if (curWeight != cur.weight
            || curWeight <= endWeight)
            continue ;

        for (const t_edge &next : edges[cur.v])
        {
            int &cmpWeight = weight[next.v];
            int nextWeight = std::min(curWeight, next.weight);

            if (cmpWeight < nextWeight)
            {
                cmpWeight = nextWeight;
                pq.push({next.v, nextWeight});
            }
        }
    }

    return (endWeight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;
    int start, end;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }
    std::cin >> start >> end;

    std::cout << dijkstra(start, end) << '\n';
    return (0);
}
