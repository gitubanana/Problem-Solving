#include <iostream>
#include <queue>
#include <unordered_set>
#include <cstring>
#include <vector>

const int MAX = 50001;

int parents[MAX];
bool dfsVisited[MAX];
bool visited[MAX];
std::vector<int> links[MAX];

void    makeParents(int cur)
{
    dfsVisited[cur] = true;

    for (const int &next : links[cur])
    {
        if (dfsVisited[next])
            continue ;

        parents[next] = cur;
        makeParents(next);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt;
    int from, to;

    std::cin >> vCnt;
    for (int i = 1; i < vCnt; ++i)
    {
        std::cin >> from >> to;
        links[from].push_back(to);
        links[to].push_back(from);
    }

    makeParents(1);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int a, b;

        std::cin >> a >> b;

        while (a != 0)
        {
            visited[a] = true;
            a = parents[a];
        }

        while (!visited[b])
        {
            b = parents[b];
        }

        std::cout << b << '\n';

        for (int v = 1; v <= vCnt; ++v)
            visited[v] = false;
    }
    return (0);
}
