#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>

template <typename T>
using t_multiset = std::multiset<T>;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int sharkCnt, eatCnt;
    int64_t curSize;
    t_multiset<int64_t> sharks;

    std::cin >> sharkCnt >> eatCnt >> curSize;
    while (sharkCnt--)
    {
        int64_t sharkSize;

        std::cin >> sharkSize;
        sharks.insert(sharkSize);
    }

    while (eatCnt--)
    {
        t_multiset<int64_t>::iterator it = sharks.lower_bound(curSize);

        if (it == sharks.end())
        {
            --it;
        }
        else
        {
            if (it == sharks.begin())
                break ;

            --it;
        }

        curSize += *it;
        sharks.erase(it);
    }

    std::cout << curSize << '\n';
    return (0);
}
