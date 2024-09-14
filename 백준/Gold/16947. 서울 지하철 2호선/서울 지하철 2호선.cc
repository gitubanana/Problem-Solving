#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const int MAX_V = 3'001;
const int CYCLE = 0;
const int DONT_MARK = -1;

int vCnt;
int dists[MAX_V];
int indegree[MAX_V];
std::queue<int> q;
std::vector<int> edges[MAX_V];

void    topologicalSort(void)
{
    while (!q.empty())
    {
        const int cur = q.front();
        q.pop();

        for (const int &next : edges[cur])
        {
            int &nextIn = indegree[next];
            if (--nextIn == 0)
            {
                q.push(next);
            }
        }
    }
}

void    dfs(int cur)
{
    for (const int &next : edges[cur])
    {
        if (indegree[next] > 0 || dists[next])
            continue ;

        dists[next] = dists[cur] + 1;
        dfs(next);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int a, b;

    std::cin >> vCnt;
    for (int e = 0; e < vCnt; ++e)
    {
        std::cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int cur = 1; cur <= vCnt; ++cur)
    {
        int &curIn = indegree[cur];

        curIn = edges[cur].size() - 1;
        if (curIn == 0)
        {
            q.push(cur);
        }
    }

    topologicalSort();
    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v] <= 0)
            continue ;

        dfs(v);
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        std::cout << dists[v] << ' ';
    }
    std::cout << '\n';
    return (0);
}
