#include <iostream>
#include <algorithm>
#include <vector>

struct t_edge
{
    int v;
    int weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight < other.weight);
    }
};

const int MAX_V = 100001;

int vCnt;
int max;
bool visited[MAX_V];
std::vector<t_edge> edges[MAX_V];

int dfs(int cur, int curWeight=0)
{
    int ret = 0;

    max = std::max(max, curWeight);
    visited[cur] = true;
    for (const t_edge &next : edges[cur])
    {
        if (visited[next.v])
            continue ;

        ret += next.weight + dfs(next.v, curWeight + next.weight);
    }
    return (ret);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int start;

    std::cin >> vCnt >> start;
    for (int e = 1; e < vCnt; ++e)
    {
        int from, to;
        int weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    int totalWeight = dfs(start);
    std::cout << (totalWeight << 1) - max << '\n';
    return (0);
}
