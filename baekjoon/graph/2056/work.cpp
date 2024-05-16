#include <iostream>
#include <algorithm>
#include <vector>

const int MAX = 10001;

int ans, vCnt;
int cost[MAX];
bool visited[MAX];
std::vector<int> way;
std::vector<int> edges[MAX];

void    dfs(int cur)
{
    visited[cur] = true;
    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        dfs(next);
    }

    way.push_back(cur);
}

void    topological_sort(void)
{
    for (int v = 1; v <= vCnt; ++v)
    {
        if (visited[v])
            continue ;

        dfs(v);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int to;
    int eCnt;

    std::cin >> vCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cin >> cost[v] >> eCnt;

        while (eCnt--)
        {
            std::cin >> to;
            edges[v].push_back(to);
        }
    }

    topological_sort();

    for (const int &cur : way)
    {
        int toAdd = 0;

        for (const int &prev : edges[cur])
        {
            toAdd = std::max(toAdd, cost[prev]);
        }

        cost[cur] += toAdd;
    }
    std::cout << *std::max_element(&cost[1], &cost[vCnt + 1]) << '\n';
    return (0);
}
