#include <iostream>
#include <cstring>

const int MAX = 150000;

int parent[MAX];
bool done[MAX];

struct t_tree
{
    int max_v;
    int cur_parent;
    
    t_tree(int root)
        : max_v(root), cur_parent(root)
    {
        done[root] = true;
        parent[root] = -1;
    }

    void cur_node(int v)
    {
        if (max_v < v)
            max_v = v;

        if (done[v] == false)
        {
            parent[v] = cur_parent;
            done[v] = true;
        }
        cur_parent = v;
    }

    void print_parent(void) const
    {
        std::cout << max_v + 1 << '\n';
        for (int v = 0; v <= max_v; ++v)
            std::cout << parent[v] << ' ';
        std::cout << '\n';
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int root;
    int input_cnt;

    std::cin >> input_cnt >> root;

    t_tree tree(root);
    while (--input_cnt)
    {
        int v;
        std::cin >> v;
        tree.cur_node(v);
    }

    tree.print_parent();
    return 0;
}
