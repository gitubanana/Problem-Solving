#include <iostream>

const int MAX = 1001;
int vCnt;
int parent[MAX];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

void union_(int x, int y)
{
    int xParent = getParent(x);
    int yParent = getParent(y);

    if (xParent > yParent)
        parent[xParent] = yParent;
    else
        parent[yParent] = xParent;
}

void initParent()
{
    for (int v = 1; v <= vCnt; ++v)
        parent[v] = v;
}

bool isTree()
{
    for (int v = 1; v <= vCnt; ++v)
    {
        if (getParent(v) != 1)
            return (false);
    }
    return (true);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int eCnt;
    int from, to;
    const char *msg[] = {"graph", "tree"};

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> vCnt >> eCnt;
        initParent();
        for (int i = 0; i < eCnt; ++i)
        {
            std::cin >> from >> to;
            if (eCnt == vCnt - 1)
                union_(from, to);
        }
        std::cout << msg[isTree()] << '\n';
    }
    return 0;
}
