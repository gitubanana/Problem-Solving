#include <iostream>
#include <vector>
#include <queue>

const int MAX_V = 100001;
const int MAX_E = 100000;
const int END_OF_STATION = -1;

bool visited[MAX_V];
std::vector<int> routes[MAX_E];
std::vector<int> stations[MAX_V];

int bfs(int start, int end)
{
    if (start == end)
        return (0);

    int transferCnt = 0;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const int cur = q.front();
            q.pop();

            for (const int &routeIdx : stations[cur])
            {
                std::vector<int> &curRoute = routes[routeIdx];

                for (const int &next : curRoute)
                {
                    if (visited[next])
                        continue ;

                    if (next == end)
                        return (transferCnt);

                    visited[next] = true;
                    q.push(next);
                }
                curRoute.clear();
            }
        }
        ++transferCnt;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;

    std::cin >> vCnt >> eCnt;
    for (int e = 0; e < eCnt; ++e)
    {
        std::vector<int> &curRoute = routes[e];

        while (true)
        {
            int v;

            std::cin >> v;
            if (v == END_OF_STATION)
                break ;

            curRoute.push_back(v);
            stations[v].push_back(e);
        }
    }

    int start, end;

    std::cin >> start >> end;
    std::cout << bfs(start, end) << '\n';
    return (0);
}
