#include <iostream>

const int MAX_V = 100'001;

int vCnt;
int parents[MAX_V];

inline int getParent(int x)
{
    int &xParent = parents[x];
    if (xParent != x)
        xParent = getParent(xParent);

    return (xParent);
}

inline void    group(int y, int x)
{
    parents[getParent(y)] = getParent(x);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;
    int ans = -1;

    std::cin >> vCnt >> eCnt;
    for (int v = 1; v <= vCnt; ++v)
    {
        parents[v] = v;
    }
    while (eCnt--)
    {
        int a, b;

        std::cin >> a >> b;
        if (getParent(a) != getParent(b))
        {
            group(a, b);
        }
        else
        {
            ++ans;
        }
    }

    for (int v = 1; v <= vCnt; ++v)
    {
        ans += (getParent(v) == v);
    }

    std::cout << ans << '\n';
    return (0);
}
