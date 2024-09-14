#include <iostream>
#include <unordered_set>

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
        std::unordered_set<int> uset;

        while (aCnt--)
        {
            std::cin >> cd;
            uset.insert(cd);
        }

        int sameCnt = 0;
        while (bCnt--)
        {
            std::cin >> cd;
            sameCnt += (uset.find(cd) != uset.end());
        }

        std::cout << sameCnt << '\n';
    }
    return (0);
}
