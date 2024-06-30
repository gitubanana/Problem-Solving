#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

struct t_edge
{
    int v;
    int weight;
};

const int MAX_V = 1e5 + 1;

int start, end;
bool visited[MAX_V];
std::vector<t_edge> edges[MAX_V];

bool bfs(int startEat)
{
    std::queue<t_edge> q;

    visited[start] = true;
    q.push({start, startEat});
    while (!q.empty())
    {
        const t_edge cur = q.front();
        q.pop();

        for (const t_edge &next : edges[cur.v])
        {
            if (cur.weight > next.weight
                || visited[next.v])
                continue ;

            if (next.v == end)
                return (true);

            visited[next.v] = true;
            q.push({next.v, cur.weight});
        }
    }
    return (false);
}

void    parametricSearch(void)
{
    int left = 1;
    int right = 1e6;
    int maxEat = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        memset(visited, false, sizeof(visited));
        if (bfs(mid))
        {
            left = mid + 1;
            maxEat = std::max(maxEat, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    std::cout << maxEat << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;

    std::cin >> vCnt >> eCnt;
    std::cin >> start >> end;
    while (eCnt--)
    {
        int from, to, weight;

        std::cin >> from >> to >> weight;
        edges[from].push_back({to, weight});
        edges[to].push_back({from, weight});
    }

    parametricSearch();
    return (0);
}
