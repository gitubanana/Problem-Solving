#include <iostream>
#include <vector>
#include <queue>

template <typename T>
using t_minQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

const int MAX_V = 32001;

int vCnt;
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

void    topologicalSort(void)
{
    t_minQ<int> pq;

    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v] != 0)
            continue ;

        pq.push(v);
    }

    while (!pq.empty())
    {
        const int cur = pq.top();
        pq.pop();

        std::cout << cur << ' ';
        for (const int &next : edges[cur])
        {
            int &nextIndegree = indegree[next];

            --nextIndegree;
            if (nextIndegree != 0)
                continue ;

            pq.push(next);
        }
    }
}

int main(void)
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
    return (0);
}
