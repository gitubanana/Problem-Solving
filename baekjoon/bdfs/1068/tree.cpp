#include <iostream>
#include <vector>

typedef std::vector<int> t_vec;

const int   MAX = 50;
int cnt, removed;

t_vec   map[MAX];

void    count_leaves(int cur_v)
{
    t_vec   &children = map[cur_v];
    int     size = children.size();

    for (int i = 0; i < children.size(); ++i)
    {
        const int   &child = children[i];

        if (child == removed)
            --size;
        else
            count_leaves(child);
    }

    if (size == 0)
        ++cnt;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int v_cnt, root;

    std::cin >> v_cnt;
    for (int v = 0; v < v_cnt; ++v)
    {
        int parent;

        std::cin >> parent;
        if (parent == -1)
            root = v;
        else
            map[parent].push_back(v);
    }
    std::cin >> removed;

    if (removed == root)
        cnt = 0;
    else
        count_leaves(root);

    std::cout << cnt << '\n';

    return 0;
}
