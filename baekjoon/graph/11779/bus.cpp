#include <iostream>
#include <vector>
#include <queue>

struct t_edge
{
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

struct t_dist
{
    const static int INF = 1e9;

    int dist;
    int from;

    t_dist() : dist(INF) {}
};

const int V_MAX = 1001;

int vCnt;
int start, end;
std::vector<int> way;
t_dist dists[V_MAX];
std::vector<t_edge> edges[V_MAX];

std::istream &operator>>(std::istream &in, t_edge &input)
{
    in >> input.to >> input.weight;
    return (in);
}

void    dijkstra(void)
{
    std::priority_queue<t_edge> pq;

    dists[start].dist = 0;
    dists[start].from = 0;
    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        const int &curV = cur.to;
        pq.pop();

        if (dists[curV].dist != cur.weight)
            continue ;

        for (const t_edge &nextEdge : edges[curV])
        {
            const int &nextV = nextEdge.to;
            t_dist &nextDist = dists[nextV];
            int toCmp = cur.weight + nextEdge.weight;

            if (nextDist.dist > toCmp)
            {
                nextDist.dist = toCmp;
                nextDist.from = curV;
                pq.push({nextV, nextDist.dist});
            }
        }
    }

    int cur = end;
    while (cur != 0)
    {
        way.push_back(cur);
        cur = dists[cur].from;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_edge edge;
    int eCnt, from;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        std::cin >> from >> edge;
        edges[from].push_back(edge);
    }
    std::cin >> start >> end;

    if (start == end)
    {
        std::cout << 0 << '\n';
        std::cout << 1 << '\n';
        std::cout << end << '\n';
        return (0);
    }

    dijkstra();
    std::cout << dists[end].dist << '\n';
    std::cout << way.size() << '\n';
    for (int i = way.size() - 1; i >= 0; --i)
        std::cout << way[i] << ' ';
    std::cout << '\n';
    return (0);
}