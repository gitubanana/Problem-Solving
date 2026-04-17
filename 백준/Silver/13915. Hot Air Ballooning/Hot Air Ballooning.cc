#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    std::string balloon;
    int size, cur, i;

    while (std::cin >> size)
    {
        std::set<int>   category;
        while (size--)
        {
            std::cin >> balloon;
            cur = 0;
            for (i = 0; i < balloon.length(); ++i)
            {
                cur |= (1 << (balloon[i] - '1'));
            }
            category.insert(cur);
        }
        std::cout << category.size() << '\n';
    }
    return 0;
}

