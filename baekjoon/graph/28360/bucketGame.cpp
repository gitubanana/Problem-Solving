#include <iostream>
#include <iomanip>
#include <vector>

const int MAX_V = 50;

bool visited[MAX_V + 1];
double buckets[MAX_V + 1];
std::vector<int> order;
std::vector<int> edges[MAX_V + 1];
std::vector<int> rEdges[MAX_V + 1];

void    dfs(int cur)
{
    visited[cur] = true;

    for (const int &next : rEdges[cur])
    {
        if (visited[next])
            continue ;

        dfs(next);
    }

    order.push_back(cur);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        edges[from].push_back(to);
        rEdges[to].push_back(from);
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        if (visited[v])
            continue ;

        dfs(v);
    }

    buckets[1] = 100;
    for (const int &cur : order)
    {
        double &curBucket = buckets[cur];

        for (const int &prev : rEdges[cur])
        {
            curBucket += buckets[prev]
                        / (edges[prev].size() + edges[prev].empty());
        }
    }

    double maxBucket = 0;
    for (int v = 1; v <= vCnt; ++v)
    {
        if (edges[v].size())
            continue ;

        maxBucket = std::max(maxBucket, buckets[v]);
    }

    std::cout << std::fixed << std::setprecision(7) << maxBucket << '\n';
    return (0);
}
