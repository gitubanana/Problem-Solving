#include <iostream>

const int   MAX = 1000001;

int parents[MAX];

int getParent(int x)
{
    if (parents[x] == x)
        return x;
    return parents[x] = getParent(parents[x]);
}

void union_(int x, int y)
{
    int xParent = getParent(x);
    int yParent = getParent(y);

    if (xParent > yParent)
        parents[xParent] = yParent;
    else
        parents[yParent] = xParent;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmd, x, y;
    int vCnt, cmdCnt;

    std::cin >> vCnt >> cmdCnt;
    ++vCnt;
    for (int v = 1; v < vCnt; ++v)
        parents[v] = v;

    while (cmdCnt--)
    {
        std::cin >> cmd >> x >> y;
        if (cmd == 0)
            union_(x, y);
        else
            std::cout << (getParent(x) == getParent(y) ? "YES" : "NO") << '\n';
    }
    return (0);
}
