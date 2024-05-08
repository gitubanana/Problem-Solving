#include <iostream>
#include <vector>
#include <climits>

struct t_edge
{
    int to;
    int weight;
};

const int MAX = 1001;

int vCnt;
int cost[MAX];
bool visited[MAX];
std::vector<t_edge> edges[MAX];

int dfs(int cur=1)
{
    visited[cur] = true;

    bool isEmpty = true;
    std::vector<t_edge> &curEdges = edges[cur];

    for (const t_edge &edge : curEdges)
    {
        if (visited[edge.to])
            continue ;

        isEmpty = false;
        cost[cur] += std::min(edge.weight, dfs(edge.to));
    }
    return (isEmpty ? INT_MAX : cost[cur]);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int eCnt;
    int from, to, weight;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt >> eCnt;
        for (int v = 1; v <= vCnt; ++v)
        {
            cost[v] = 0;
            edges[v].clear();
            visited[v] = false;
        }
        while (eCnt--)
        {
            std::cin >> from >> to >> weight;
            edges[from].push_back({to, weight});
            edges[to].push_back({from, weight});
        }

        std::cout << (vCnt == 1 ? 0 : dfs()) << '\n';
    }
    return (0);
}
