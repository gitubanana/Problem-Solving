#include <iostream>
#include <vector>

const int V_CNT = 100;
const int START = 0;
const int END = V_CNT - 1;

bool visited[V_CNT];
std::vector<int> edges[V_CNT];

bool dfs(int cur=0)
{
    if (cur == END)
    {
        return (true);
    }

    visited[cur] = true;
    for (const int &next : edges[cur])
    {
        if (visited[next])
            continue ;

        if (dfs(next))
            return (true);
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt = 10;

    while (testCnt--)
    {
        int t, eCnt;

        std::cin >> t >> eCnt;
        for (int v = 0; v < V_CNT; ++v)
        {
            visited[v] = false;
            edges[v].clear();
        }
        while (eCnt--)
        {
            int from, to;

            std::cin >> from >> to;
            edges[from].push_back(to);
        }

        std::cout << '#' << t << ' ' << dfs() << '\n';
    }

    return (0);
}
