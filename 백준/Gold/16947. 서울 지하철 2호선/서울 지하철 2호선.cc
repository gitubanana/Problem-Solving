#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

const int MAX_V = 3'001;
const int CYCLE = 0;
const int DONT_MARK = -1;

int vCnt;
int cycleEnd;
bool isCycle[MAX_V];
bool visited[MAX_V];
std::vector<int> edges[MAX_V];

bool    dfs(int cur=1, int prev=0)
{
    visited[cur] = true;
    for (const int &next : edges[cur])
    {
        if (next == prev)
            continue ;

        if (visited[next])
        {
            cycleEnd = next;
            isCycle[cur] = true;
            return (true);
        }

        if (dfs(next, cur))
        {
            if (cycleEnd != DONT_MARK)
            {
                isCycle[cur] = true;
            }

            if (cycleEnd == cur)
            {
                cycleEnd = DONT_MARK;
            }

            return (true);
        }
    }

    return (false);
}

int bfs(int start)
{
    if (isCycle[start])
        return (0);

    int dist = 0;
    std::queue<int> q;

    memset(visited, false, sizeof(visited));
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        ++dist;
        while (qSize--)
        {
            const int cur = q.front();
            q.pop();

            for (const int &next : edges[cur])
            {
                if (visited[next])
                    continue ;

                if (isCycle[next])
                    return (dist);

                visited[next] = true;
                q.push(next);
            }
        }
    }

    return (-1);
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

    dfs();
    // std::cout << "=== isCycle ===" << '\n';
    // for (int v = 1; v <= vCnt; ++v)
    // {
    //     std::cout << isCycle[v] << ' ';
    // }
    // std::cout << '\n';

    for (int v = 1; v <= vCnt; ++v)
    {
        std::cout << bfs(v) << ' ';
    }
    std::cout << '\n';
    return (0);
}
