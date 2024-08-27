#include <iostream>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;
};

const int MAX_V = 1001;

int vCnt;
int prev[MAX_V];
int dists[MAX_V];
int indegree[MAX_V];
std::vector<t_edge> edges[MAX_V];

void    topologicalSort(int start=1)
{
    std::queue<int> q;

    q.push(start);
    while (!q.empty())
    {
        const int cur = q.front();
        const int &curDist = dists[cur];
        q.pop();

        for (const t_edge &next : edges[cur])
        {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.weight;

            if (cmpDist < nextDist)
            {
                cmpDist = nextDist;
                prev[next.v] = cur;
            }

            if (--indegree[next.v] || next.v == start)
                continue ;

            q.push(next.v);
        }
    }
}

void    printAns(int start=1)
{
    int cur = start;
    std::vector<int> path;

    do
    {
        path.push_back(cur);
        cur = prev[cur];
    } while (cur != start);
    path.push_back(start);

    std::cout << dists[start] << '\n';
    for (int i = path.size() - 1; i >= 0; --i)
    {
        std::cout << path[i] << ' ';
    }
    std::cout << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from;
        t_edge edge;

        std::cin >> from >> edge.v >> edge.weight;
        ++indegree[edge.v];
        edges[from].push_back(edge);
    }

    topologicalSort();
    printAns();
    return (0);
}
