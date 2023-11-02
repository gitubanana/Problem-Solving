#include <iostream>
#include <vector>
#include <algorithm>

struct t_edge
{
    int to;
    int weight;
};

typedef std::vector<t_edge> t_vec;

const int   MAX = 100001;

t_vec linked[MAX];
bool  visited[MAX];
int   v_cnt, ans;

int dfs(int cur, int cur_weight)
{
    t_vec   &linked_nodes = linked[cur];

    visited[cur] = true;
    int cur_max1 = 0, cur_max2 = 0;
    for (size_t i = 0; i < linked_nodes.size(); ++i)
    {
        t_edge  &cur_edge = linked_nodes[i];

        if (visited[cur_edge.to] == true)
            continue ;

        int tmp = dfs(cur_edge.to, cur_edge.weight);

        if (cur_max1 < tmp)
            cur_max2 = cur_max1, cur_max1 = tmp;
        else if (cur_max2 < tmp)
            cur_max2 = tmp;
    }

    ans = std::max(ans, cur_max1 + cur_max2);
    return (cur_max1 + cur_weight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_edge edge;
    int    root = 1, v;

    std::cin >> v_cnt;
    for (int i = 0; i < v_cnt; ++i)
    {
        std::cin >> v;
        while (1)
        {
            std::cin >> edge.to;
            if (edge.to == -1)
                break ;
            std::cin >> edge.weight;
            linked[v].push_back(edge);
        }
    }

    dfs(root, 0);
    std::cout << ans << '\n';

    return (0);
}
