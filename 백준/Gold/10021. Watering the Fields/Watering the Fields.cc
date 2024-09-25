#include <iostream>
#include <algorithm>
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

struct t_pos
{
    int y, x;

    inline int getDist(const t_pos &other) const
    {
        int yDist = std::abs(this->y - other.y);
        int xDist = std::abs(this->x - other.x);

        return yDist*yDist + xDist*xDist;
    }
};

const int MAX_V = 2001;

int vCnt, atLeast;
t_pos pos[MAX_V];
bool visited[MAX_V];

int prim(int start=1)
{
    int madeEcnt = 0;
    int totalWeight = -atLeast;
    std::priority_queue<t_edge> pq;

    pq.push({start, atLeast});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (visited[cur.v] || cur.weight < atLeast)
            continue ;

        totalWeight += cur.weight;
        if (++madeEcnt == vCnt)
            return (totalWeight);

        t_pos &curPos = pos[cur.v];

        visited[cur.v] = true;
        for (int next = 1; next <= vCnt; ++next)
        {
            if (visited[next])
                continue ;

            pq.push({next, curPos.getDist(pos[next])});
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt >> atLeast;
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cin >> pos[v].y >> pos[v].x;
    }

    std::cout << prim() << '\n';
    return (0);
}
