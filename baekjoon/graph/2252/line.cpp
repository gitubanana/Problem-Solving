#include <iostream>
#include <vector>

typedef std::vector<int> t_vec;

const int   MAX = 32001;

t_vec map[MAX];
bool  visited[MAX];
t_vec ans;
int   v_cnt;

void    dfs(int cur_v)
{
    visited[cur_v] = true;

    t_vec   &linked = map[cur_v];
    for (const int &next : linked)
    {
        if (!visited[next])
            dfs(next);
    }

    ans.push_back(cur_v);
}

void    topological_sort(void)
{
    for (int v = 1; v <= v_cnt; ++v)
    {
        if (!visited[v])
            dfs(v);
    }

    for (int i = ans.size() - 1; i >= 0; --i)
        std::cout << ans[i] << ' ';
    std::cout << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int e_cnt;

    std::cin >> v_cnt >> e_cnt;
    while (e_cnt--)
    {
        int from, to;
        std::cin >> from >> to;
        map[from].push_back(to);
    }

    topological_sort();
    return (0);
}
