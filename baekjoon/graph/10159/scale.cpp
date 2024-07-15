#include <iostream>
#include <cstring>
#include <vector>
#define INIT_VISITED memset(visited, false, sizeof(visited))

const int MAX_V = 100 + 1;

bool visited[MAX_V];
std::vector<int> fEdges[MAX_V];
std::vector<int> rEdges[MAX_V];

int dfs(int cur, std::vector<int> *edges)
{
    int ret = 1;

    visited[cur] = true;
    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        ret += dfs(next, edges);
    }
    return (ret);
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
        fEdges[from].push_back(to);
        rEdges[to].push_back(from);
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        INIT_VISITED;
        int forwardCnt = dfs(v, fEdges);
        int reverseCnt = dfs(v, rEdges);

        std::cout << (vCnt + 1 - (forwardCnt + reverseCnt)) << '\n';
    }

    return (0);
}
