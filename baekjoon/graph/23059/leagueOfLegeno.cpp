#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

template <typename T>
using t_minQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;

int eCnt;
std::vector<std::string> order;
std::unordered_map<std::string, int> indegree;
std::unordered_map<std::string, std::vector<std::string>> edges;

void topologicalSort(void)
{
    t_minQ<std::string> pq;

    for (std::pair<const std::string, int> &cur : indegree)
    {
        const int &indegreeNum = cur.second;
        if (indegreeNum != 0)
            continue ;

        pq.push(cur.first);
    }

    while (!pq.empty())
    {
        int qSize = pq.size();
        std::vector<std::string> toPush;

        while (qSize--)
        {
            const std::string cur = pq.top();
            pq.pop();

            order.push_back(cur);
            for (const std::string &next : edges[cur])
            {
                int &nextIndegree = indegree[next];

                --nextIndegree;
                if (nextIndegree == 0)
                {
                    toPush.push_back(next);
                }
            }
        }

        for (const std::string &item : toPush)
        {
            pq.push(item);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> eCnt;
    while (eCnt--)
    {
        std::string from, to;

        std::cin >> from >> to;
        ++indegree[to];
        int &fromIn = indegree[from];
        edges[from].push_back(to);
    }

    topologicalSort();

    if (order.size() != indegree.size())
    {
        std::cout << "-1" << '\n';
    }
    else
    {
        for (const std::string &item : order)
        {
            std::cout << item << '\n';
        }
    }
    return (0);
}
