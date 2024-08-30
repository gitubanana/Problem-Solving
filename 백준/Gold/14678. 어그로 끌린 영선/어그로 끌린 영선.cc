#include <iostream>
#include <cstring>
#include <vector>

enum e_idx
{
    LEFT = 0,
    RIGHT
};

const int MAX_V = 1e6 + 1;

int vCnt, odd, even;
std::vector<int> edges[MAX_V];

void dfs(int cur, int prev=-1, int depth=0)
{
    if (edges[cur].size() == 1)
    {
        if (depth & 1)
            ++odd;
        else
            ++even;

        return ;
    }

    for (const int &next : edges[cur])
    {
        if (next == prev)
            continue ;

        dfs(next, cur, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    if (vCnt == 1)
    {
        std::cout << "1" << '\n';
        return (0);
    }

    for (int e = 1; e < vCnt; ++e)
    {
        int from, to;

        std::cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    for (int root = 1; root <= vCnt; ++root)
    {
        if (edges[root].size() > 1)
        {
            dfs(root);
            break ;
        }
    }

    int max = std::max(odd, even);
    if (max == vCnt - 1)
    {
        std::cout << vCnt - 2 << '\n';
    }
    else
    {
        std::cout << max << '\n';
    }
    return (0);
}
