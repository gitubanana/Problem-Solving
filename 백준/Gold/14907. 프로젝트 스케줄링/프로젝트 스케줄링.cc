#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <vector>

const int MAX_V = 26;

int days[MAX_V];
int calDays[MAX_V];
int indegree[MAX_V];
std::vector<int> edges[MAX_V];

void    topologicalSort(void)
{
    std::queue<int> q;

    for (int v = 0; v < MAX_V; ++v)
    {
        if (indegree[v] || !days[v])
            continue ;

        q.push(v);
        calDays[v] = days[v];
    }

    while (!q.empty())
    {
        const int cur = q.front();
        const int &curCalDay = calDays[cur];
        q.pop();

        for (const int &next : edges[cur])
        {
            int &nextCalDay = calDays[next];

            nextCalDay = std::max(
                nextCalDay,
                curCalDay + days[next]
            );

            if (--indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    char curCh;
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::string prevs;
        std::stringstream ss(line);

        ss >> curCh;
        int cur = curCh - 'A';

        ss >> days[cur] >> prevs;
        for (const char &prevCh : prevs)
        {
            int prev = prevCh - 'A';

            edges[prev].push_back(cur);
            ++indegree[cur];
        }
    }

    topologicalSort();
    std::cout << *std::max_element(calDays, calDays + MAX_V) << '\n';
    return (0);
}
