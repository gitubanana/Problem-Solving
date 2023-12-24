#include <iostream>
#include <vector>
#include <queue>

typedef std::vector<int> t_vec;

const int   MAX = 501;

int vCnt;
int time_[MAX];
int indegree[MAX];
t_vec orders;
t_vec links[MAX];

void    topological_sort()
{
    std::queue<int> q;

    for (int v = 1; v <= vCnt; ++v)
    {
        if (indegree[v] == 0)
            q.push(v);
    }

    while (!q.empty())
    {
        int &cur = q.front();

        orders.push_back(cur);
        for (int &next : links[cur])
        {
            --indegree[next];
            if (indegree[next] == 0)
                q.push(next);
        }
        q.pop();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int from = 1; from <= vCnt; ++from)
    {
        int to;

        std::cin >> time_[from];
        while (true)
        {
            std::cin >> to;
            if (to == -1)
                break ;
            ++indegree[to];
            links[from].push_back(to);
        }
    }

    topological_sort();

    for (int i = orders.size() - 1; i >= 0; --i)
    {
        int &cur = orders[i];
        int to_plus = 0;

        for (int &prev: links[cur])
            to_plus = std::max(to_plus, time_[prev]);

        time_[cur] += to_plus;
    }

    for (int v = 1; v <= vCnt; ++v)
        std::cout << time_[v] << '\n';

    return (0);
}
