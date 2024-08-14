#include <iostream>
#include <queue>
#include <vector>

const int MAX_V = 1001;

int vCnt;
int order[MAX_V];
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

void topologicalSort()
{
    std::queue<int> q;
    
    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v] == 0)
        {
            order[v] = 1;
            q.push(v);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        
        for (int &next : edges[cur])
        {
            --indegree[next];
            if (indegree[next] == 0)
            {
                order[next] = order[cur] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int from, to;

        std::cin >> from >> to;
        ++indegree[to];
        edges[from].push_back(to);
    }

    topologicalSort();
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cout << order[v] << ' ';
    }
    std::cout << '\n';

    return 0;

}