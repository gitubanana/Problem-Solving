#include <iostream>
#include <cstring>
#include <vector>

typedef std::vector<int> t_vec;

t_vec *map;
bool  *visited;

bool    dfs(int cur_v, int parent)
{
    visited[cur_v] = true;

    t_vec   &linked = map[cur_v];
    for (const int &next : linked)
    {
        if (next == parent)
            continue ;

        if (visited[next])
            return (false);

        if (!dfs(next, cur_v))
            return (false);
    }
    return (true);
}

int count_trees(int v_cnt)
{
    int cnt = 0;

    for (int v = 1; v <= v_cnt; ++v)
    {
        if (visited[v] == false && dfs(v, 0))
            ++cnt;
    }
    return (cnt);
}

void    print_tree_cnt(int v_cnt, int case_cnt)
{
    static const char *print_msg[] 
                            = {"No trees.", "There is one tree."};
    int tree_cnt = count_trees(v_cnt);

    std::cout << "Case " << case_cnt << ": ";
    if (tree_cnt <= 1)
        std::cout << print_msg[tree_cnt];
    else
        std::cout << "A forest of " << tree_cnt << " trees.";
    std::cout << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int from, to;
    int v_cnt, e_cnt;

    for (int case_cnt = 1; ; ++case_cnt)
    {
        std::cin >> v_cnt >> e_cnt;
        if (v_cnt == 0 && e_cnt == 0)
            break ;

        map = new t_vec[v_cnt + 1];
        visited = new bool[v_cnt + 1];
        memset(visited, false, v_cnt + 1);
        while (e_cnt--)
        {
            std::cin >> from >> to;
            map[from].push_back(to);
            map[to].push_back(from);
        }

        print_tree_cnt(v_cnt, case_cnt);
        delete[] map;
        delete[] visited;
    }
    return (0);
}
