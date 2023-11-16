#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

typedef std::priority_queue
        <int, std::vector<int>>
        t_link;

const int   MAX = 100001;

int     ans[MAX];
t_link  map[MAX];

void    dfs(int cur_v, int depth)
{
    ans[cur_v] = depth;

    t_link    &linked = map[cur_v];
    while (!linked.empty())
    {
        const int &next = linked.top();
        if (ans[next] == 0)
            dfs(next, depth + 1);
        linked.pop();
    }
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int from, to;
    int v_cnt, e_cnt, start;

    std::cin >> v_cnt >> e_cnt >> start;
    while (e_cnt)
    {
        std::cin >> from >> to;
        map[from].push(to);
        map[to].push(from);
        --e_cnt;
    }

    dfs(start, 1);

    for (int v = 1; v <= v_cnt; ++v)
    {
        if (ans[v] == 0)
            std::cout << "-1";
        else
            std::cout << ans[v] - 1;
        std::cout << '\n';
    }

    return 0;
}
