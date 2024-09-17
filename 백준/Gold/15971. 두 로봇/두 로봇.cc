#include <iostream>
#include <climits>
#include <vector>

struct t_edge
{
    int v;
    int weight;
};

const int MAX_V = 100'000 + 1;

int vCnt;
int minDist = INT_MAX;
int aDists[MAX_V];
std::vector<t_edge> edges[MAX_V];

void    dfs(int cur, int curDist=0, int prev=-1)
{
    aDists[cur] = curDist;
    for (const t_edge &next : edges[cur])
    {
        if (next.v == prev)
            continue ;

        dfs(next.v, curDist + next.weight, cur);
    }
}

void    dfs2(int cur, int curDist=0, int prev=-1)
{
    for (const t_edge &next : edges[cur])
    {
        if (next.v == prev)
            continue ;

        minDist = std::min(minDist, aDists[next.v] + curDist);
        dfs2(next.v, curDist + next.weight, cur);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int a, b;

    std::cin >> vCnt >> a >> b;
    for (int e = 1; e < vCnt; ++e)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    if (a == b)
    {
        minDist = 0;
    }
    else
    {
        dfs(a);
        dfs2(b);
    }

    std::cout << minDist << '\n';
    return (0);
}
