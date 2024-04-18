#include <iostream>
#include <queue>
#include <vector>

const int INF = 1e9;
const int V_MAX = 101;

int changes[V_MAX];
std::vector<int> edges[V_MAX];

int vCnt;
int start, dest;

void    dijkstra(void)
{
    for (int v = 1; v <= vCnt; ++v)
        changes[v] = INF;

    std::queue<int> q;

    q.push(start);
    changes[start] = 0;
    while (!q.empty())
    {
        const int &cur = q.front();

        for (int i = 0; i < edges[cur].size(); ++i)
        {
            const int &next = edges[cur][i];
            int nextChange = changes[cur] + (i != 0);

            if (changes[next] > nextChange)
            {
                changes[next] = nextChange;
                q.push(next);
            }
        }
        q.pop();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt >> start >> dest;
    for (int from = 1; from <= vCnt; ++from)
    {
        int to;
        int edgeCnt;

        std::cin >> edgeCnt;
        while (edgeCnt--)
        {
            std::cin >> to;
            edges[from].push_back(to);
        }
    }

    dijkstra();
    std::cout << (changes[dest] == INF ? -1 : changes[dest]) << '\n';
    return (0);
}
