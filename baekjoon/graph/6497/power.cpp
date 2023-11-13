#include <iostream>
#include <vector>
#include <algorithm>

struct t_edge
{
    int from;
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const {
        return (this->weight < other.weight);
    }
};

typedef std::vector<t_edge> t_vec;

const int   MAX = 200000;

int   v_cnt;
int   parent[MAX];

int find(int v)
{
    if (parent[v] == v)
        return (v);
    return parent[v] = find(parent[v]);
}

void    _union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent < y_parent)
        parent[y_parent] = x_parent;
    else
        parent[x_parent] = y_parent;
}

int min_weight(t_vec &vec)
{
    int total_weight = 0;

    for (int i = 0; i < v_cnt; ++i)
        parent[i] = i;

    --v_cnt;
    int vec_size = vec.size();
    for (int i = 0; i < vec_size && v_cnt; ++i)
    {
        const t_edge &cur_edge = vec[i];

        if (find(cur_edge.from) != find(cur_edge.to))
        {
            _union(cur_edge.from, cur_edge.to);
            --v_cnt;
            total_weight += cur_edge.weight;
        }
    }
    return (total_weight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        t_vec  vec;
        t_edge edge;
        int    e_cnt, sum = 0;

        std::cin >> v_cnt >> e_cnt;
        if (v_cnt == 0 && e_cnt == 0)
            break ;

        while (e_cnt--)
        {
            std::cin >> edge.from >> edge.to >> edge.weight;
            sum += edge.weight;
            vec.push_back(edge);
        }

        std::sort(vec.begin(), vec.end());
        std::cout << sum - min_weight(vec) << '\n';
    }
    return (0);
}
