#include <iostream>
#include <vector>
#include <queue>

const int MAX_V = 1e5 + 1;

int vCnt, toFind, cnt;
bool visited[MAX_V];
std::vector<int> edges[MAX_V];
std::vector<int> rEdges[MAX_V];

void dfs(int cur, std::vector<int> edges[MAX_V])
{
    ++cnt;
    visited[cur] = true;

    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue;

        dfs(next, edges);
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt >> toFind;
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        edges[from].push_back(to);
        rEdges[to].push_back(from);
    }

    dfs(toFind, rEdges);
    std::cout << cnt << ' ';

    cnt = 0;
    dfs(toFind, edges);
    std::cout << vCnt - cnt + 1 << '\n';
    return 0;
}
