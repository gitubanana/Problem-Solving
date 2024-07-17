#include <iostream>

const int MAX_V = 1e6 + 1;

int parents[MAX_V];
int childrenCnt[MAX_V];

void    initParents(void)
{
    for (int v = 1; v < MAX_V; ++v)
    {
        parents[v] = v;
    }
}

int getParent(int x)
{
    int &xParent = parents[x];
    if (xParent != x)
    {
        xParent = getParent(xParent);
    }

    return (xParent);
}

void group(int y, int x)
{
    int yParent = getParent(y);
    int xParent = getParent(x);

    if (yParent == xParent)
        return ;

    parents[yParent] = xParent;
    childrenCnt[xParent] += childrenCnt[yParent] + 1;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> cmdCnt;
    initParents();
    while (cmdCnt--)
    {
        char cmd;

        std::cin >> cmd;
        switch (cmd)
        {
        case 'I':
            {
                int a, b;

                std::cin >> a >> b;
                group(a, b);
            }
            break;
        default:
            {
                int a;

                std::cin >> a;
                std::cout << childrenCnt[getParent(a)] + 1 << '\n';
            }
            break;
        }
    }
    return (0);
}
