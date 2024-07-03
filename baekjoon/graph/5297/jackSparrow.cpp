#include <iostream>
#include <deque>
#include <vector>
#include <climits>

struct t_edge
{
    int v;
    bool guard;
};

int start, end;
std::vector<int> guardCnt;
std::vector<std::vector<t_edge>> edges;

int bfs()
{
    if (start == end)
        return 0;

    int &endGuard = guardCnt[end];
    std::deque<int> q;

    guardCnt[start] = 0;
    q.push_front(start);
    while (!q.empty())
    {
        const int cur = q.front();
        const int &curCnt = guardCnt[cur];
        q.pop_front();

        if (endGuard <= curCnt)
            continue;

        for (const t_edge &next : edges[cur])
        {
            int &cmpCnt = guardCnt[next.v];
            int nextCnt = curCnt + next.guard;

            if (cmpCnt <= nextCnt)
                continue;

            cmpCnt = nextCnt;
            if (next.guard)
                q.push_back(next.v);
            else
                q.push_front(next.v);
        }
    }

    return (endGuard);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;

    std::cin >> vCnt >> eCnt >> start >> end;
    guardCnt = std::vector<int>(vCnt, INT_MAX);
    edges = std::vector<std::vector<t_edge>>(vCnt, std::vector<t_edge>());
    while (eCnt--)
    {
        int from, to;
        bool guard;

        std::cin >> from >> to >> guard;
        edges[from].push_back({to, guard});
        edges[to].push_back({from, guard});
    }

    int guardCnt = bfs();
    if (guardCnt == INT_MAX)
        std::cout << "It's over with Captain Jack. At least till Pirates of the Caribbean 3.";
    else
        std::cout << guardCnt << " native(s) on the easiest way for Captain Jack.";
    std::cout << '\n';

    return 0;
}