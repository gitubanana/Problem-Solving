#include <iostream>
#include <unordered_set>
#include <vector>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int aCnt, bCnt;
        std::cin >> aCnt >> bCnt;

        if (aCnt == 0 && bCnt == 0)
            break ;

        int cd;
        std::vector<int> a;
        std::vector<int> b;

        for (int i = 0; i < aCnt; ++i)
        {
            std::cin >> cd;
            a.push_back(cd);
        }
        for (int i = 0; i < bCnt; ++i)
        {
            std::cin >> cd;
            b.push_back(cd);
        }

        int sameCnt = 0;
        int aIdx = 0, bIdx = 0;
        while (aIdx < aCnt && bIdx < bCnt)
        {
            const int &aElem = a[aIdx];
            const int &bElem = b[bIdx];

            if (aElem < bElem)
            {
                ++aIdx;
            }
            else if (aElem > bElem)
            {
                ++bIdx;
            }
            else
            {
                ++sameCnt;
                ++aIdx, ++bIdx;
            }
        }

        std::cout << sameCnt << '\n';
    }
    return (0);
}
