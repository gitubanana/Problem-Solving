#include <iostream>
#include <vector>

struct t_edge
{
    int to;
    int weight;
};

typedef std::vector<t_edge> t_vec;

const int   MAX = 10001;

t_vec children[MAX];
int   v_cnt, ans;

int dfs(int cur, int cur_weight)
{
    t_vec   &cur_children = children[cur];

    int cur_max1 = 0, cur_max2 = 0;
    for (size_t i = 0; i < cur_children.size(); ++i)
    {
        t_edge  &cur_edge = cur_children[i];

        int tmp;

        if (children[cur_edge.to].size() > 0)
            tmp = dfs(cur_edge.to, cur_edge.weight);
        else
            tmp = cur_edge.weight;

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
    int    root = 1, parent;

    std::cin >> v_cnt;
    for (int i = 1; i < v_cnt; ++i)
    {
        std::cin >> parent >> edge.to >> edge.weight;
        children[parent].push_back(edge);
    }

    dfs(root, 0);
    std::cout << ans << '\n';

    return (0);
}
