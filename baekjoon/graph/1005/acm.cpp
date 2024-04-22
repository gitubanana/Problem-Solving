#include <iostream>
#include <vector>
#include <queue>

const int MAX = 1001;

bool visited[MAX];
int buildTime[MAX];
std::vector<int> order;
std::vector<int> edges[MAX];

void    makeOrder(int cur)
{
    visited[cur] = true;

    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        makeOrder(next);
    }
    order.push_back(cur);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int from, to;
    int vCnt, eCnt, goal;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt >> eCnt;
        for (int v = 1; v <= vCnt; ++v)
        {
            std::cin >> buildTime[v];
            visited[v] = false;
            edges[v].clear();
        }
        while (eCnt--)
        {
            std::cin >> from >> to;
            edges[to].push_back(from);
        }
        std::cin >> goal;

        order.clear();
        makeOrder(goal);

        for (const int &cur : order)
        {
            int toPlus = 0;

            for (const int &prev : edges[cur])
                toPlus = std::max(toPlus, buildTime[prev]);

            buildTime[cur] += toPlus;
        }
        std::cout << buildTime[goal] << '\n';
    }
    return (0);
}
