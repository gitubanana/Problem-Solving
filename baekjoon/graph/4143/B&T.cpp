#include <iostream>
#include <unordered_map>

const int MAX_V = 1e5 * 2 + 1;

int parents[MAX_V];
int childrenCnt[MAX_V];
std::unordered_map<std::string, int> strToInt;

inline int &getOrMakeId(const std::string &str, int &id)
{
    int &strId = strToInt[str];
    if (strId == 0)
    {
        strId = ++id;
        parents[id] = id;
        childrenCnt[id] = 0;
    }

    return (strId);
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

void    group(int y, int x)
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

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int eCnt;
        int id = 0;
        std::string a, b;

        std::cin >> eCnt;
        while (eCnt--)
        {
            std::cin >> a >> b;
            int &aId = getOrMakeId(a, id);
            int &bId = getOrMakeId(b, id);

            group(aId, bId);
            std::cout << childrenCnt[getParent(aId)] + 1 << '\n';
        }

        strToInt.clear();
    }
    return (0);
}
