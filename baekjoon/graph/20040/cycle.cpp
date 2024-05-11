#include <iostream>

const int MAX = 500000;

int vCnt;
int parents[MAX];

int getParent(int x)
{
    int &xParent = parents[x];

    if (x == xParent)
        return (x);

    return xParent = getParent(xParent);
}

void    union_(int x, int y)
{
    int &xParent = parents[getParent(x)];
    int &yParent = parents[getParent(y)];

    if (xParent > yParent)
        xParent = yParent;
    else
        yParent = xParent;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    int eCnt;
    int from, to;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        parents[v] = v;
    }
    for (int turn = 1; turn <= eCnt; ++turn)
    {
        std::cin >> from >> to;

        if (getParent(from) == getParent(to))
        {
            ans = turn;
            break ;
        }
        union_(from, to);
    }

    std::cout << ans << '\n';
    return (0);
}
