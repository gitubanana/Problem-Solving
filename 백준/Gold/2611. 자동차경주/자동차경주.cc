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
int dists[MAX_V];
int indegree[MAX_V];
std::vector<int> path[MAX_V];
std::vector<t_edge> edges[MAX_V];

void    topologicalSort(int start=1)
{
    std::queue<int> q;

    q.push(start);
    path[start].push_back(start);
    while (!q.empty())
    {
        const int curV = q.front();
        const int &curDist = dists[curV];
        q.pop();

        for (const t_edge &next : edges[curV])
        {
            int &cmpDist = dists[next.v];
            int nextDist = curDist + next.weight;

            if (cmpDist < nextDist)
            {
                cmpDist = nextDist;
                path[next.v] = path[curV];
                path[next.v].push_back(next.v);
            }

            if (--indegree[next.v])
                continue ;

            q.push(next.v);
        }
    }
}

void    printAns(int start=1)
{
    std::cout << dists[start] << '\n';
    for (const int &cur : path[start])
    {
        std::cout << cur << ' ';
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
