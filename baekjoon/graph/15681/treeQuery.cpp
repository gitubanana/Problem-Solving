#include <iostream>
#include <vector>

const int MAX = 1e5 + 1;

int vCnt, root;
int childrenCnt[MAX];
std::vector<int> edges[MAX];

void    dfs(int cur)
{
    childrenCnt[cur] = 1;
    for (const int &next : edges[cur])
    {
        if (childrenCnt[next])
            continue ;

        dfs(next);
        childrenCnt[cur] += childrenCnt[next];
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int queryCnt;
    int from, to;

    std::cin >> vCnt >> root >> queryCnt;
    for (int i = 1; i < vCnt; ++i)
    {
        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    dfs(root);

    int subRoot;
    while (queryCnt--)
    {
        std::cin >> subRoot;
        std::cout << childrenCnt[subRoot] << '\n';
    }
    return (0);
}
