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

const int   MAX = 100001;

t_vec vec;
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

int min_weight(void)
{
    int total_weight = 0;

    for (int i = 1; i <= v_cnt; ++i)
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
            if (v_cnt)
                total_weight += cur_edge.weight;
        }
    }
    return (total_weight);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_edge edge;
    int    e_cnt;

    std::cin >> v_cnt >> e_cnt;
    for (int i = 0; i < e_cnt; ++i)
    {
        std::cin >> edge.from >> edge.to >> edge.weight;
        vec.push_back(edge);
    }

    std::sort(vec.begin(), vec.end());
    std::cout << min_weight() << '\n';
    return (0);
}
