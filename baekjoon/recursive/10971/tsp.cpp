#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>

const int   MAX = 10;
const int   CANNOT_GO = 0;
const int   INF = 900000000;

int map[MAX][MAX];
int visited[MAX];
int v_cnt, start;

int get_travel_cost(int cur, int depth)
{
    int total_cost = INF;

    if (depth == v_cnt)
    {
        if (map[cur][start] == CANNOT_GO)
            return (INF);
        return (map[cur][start]);
    }

    visited[cur] = 1;
    for (int next = 0; next < v_cnt; ++next)
    {
        const int   &cost = map[cur][next];

        if (cost == CANNOT_GO || visited[next])
            continue ;

        total_cost = std::min(total_cost, cost + get_travel_cost(next, depth + 1));
    }
    visited[cur]= 0;

    return (total_cost);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int from, to;
    int min_cost = INT_MAX;

    std::cin >> v_cnt;
    for (from = 0; from < v_cnt; ++from)
        for (to = 0; to < v_cnt; ++to)
            std::cin >> map[from][to];

    std::cout << get_travel_cost(start, 1) << '\n';
    return (0);
}
