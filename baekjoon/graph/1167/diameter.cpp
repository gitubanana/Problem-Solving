#include <iostream>
#include <vector>
#include <algorithm>

struct t_edge
{
    int v;
    int weight;
};

const int   MAX = 100001;

int vCnt, farthestNode, maxDist;
bool  visited[MAX];
std::vector<t_edge> edges[MAX];

void    findFarthestNode(int cur=1, int curDist=0)
{
    if (maxDist < curDist)
    {
        maxDist = curDist;
        farthestNode = cur;
    }

    visited[cur] = true;
    for (const t_edge &next : edges[cur])
    {
        if (visited[next.v])
            continue ;

        findFarthestNode(
            next.v,
            curDist + next.weight
        );
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int i = 0; i < vCnt; ++i)
    {
        int from, to, weight;

        std::cin >> from;
        while (1)
        {
            std::cin >> to;
            if (to == -1)
                break ;

            std::cin >> weight;
            edges[from].push_back({to, weight});
        }
    }

    findFarthestNode();

    maxDist = 0;
    for (int v = 1; v <= vCnt; ++v)
    {
        visited[v] = false;
    }
    findFarthestNode(farthestNode);

    std::cout << maxDist << '\n';
    return (0);
}
