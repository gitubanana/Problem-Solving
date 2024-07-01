#include <iostream>
#include <unordered_set>

const int MAX_V = 1001;

int parent[MAX_V];

int getParent(int x)
{
    int &xParent = parent[x];

    if (xParent != x)
        xParent = getParent(xParent);

    return (xParent);
}

void    group(int x, int y)
{
    parent[getParent(x)] = getParent(y);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt, vCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt;
        for (int v = 1; v <= vCnt; ++v)
        {
            parent[v] = v;
        }
        for (int from = 1; from <= vCnt; ++from)
        {
            int to;

            std::cin >> to;
            group(from, to);
        }

        std::unordered_set<int> cycle;
        for (int v = 1; v <= vCnt; ++v)
        {
            cycle.insert(getParent(v));
        }

        std::cout << cycle.size() << '\n';
    }
    return (0);
}
