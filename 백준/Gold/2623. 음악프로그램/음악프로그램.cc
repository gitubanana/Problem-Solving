#include <iostream>
#include <vector>
#include <queue>

const int MAX_SIZE = 1001;

int vCnt;
int indegree[MAX_SIZE];
std::vector<int> edges[MAX_SIZE];

void    topologicalSort(void)
{
    std::queue<int> q;
    std::vector<int> order;

    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v])
            continue ;

        q.push(v);
    }

    while (!q.empty())
    {
        const int cur = q.front();
        q.pop();

        order.push_back(cur);
        for (const int &next : edges[cur])
        {
            if (--indegree[next])
                continue ;

            q.push(next);
        }
    }

    if (order.size() != vCnt)
    {
        std::cout << '0' << '\n';
        return ;
    }

    for (const int &cur : order)
    {
        std::cout << cur << '\n';
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int orderCnt;

    std::cin >> vCnt >> orderCnt;
    while (orderCnt--)
    {
        int eCnt;
        int cur, next;

        std::cin >> eCnt >> cur;
        while (--eCnt)
        {
            std::cin >> next;
            ++indegree[next];
            edges[cur].push_back(next);
            cur = next;
        }
    }

    topologicalSort();
    return (0);
}
