#include <iostream>
#include <algorithm>

const int MAX = 1000000;

int people[MAX];

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> people[i];
    }

    int primary, secondary;
    std::cin >> primary >> secondary;
    
    long long ans = size;
    for (int i = 0; i < size; ++i)
    {
        int &toWatch = people[i];

        toWatch -= primary;
        if (toWatch <= 0)
            continue ;

        ans += toWatch / secondary + (toWatch % secondary != 0);
    }
    std::cout << ans << '\n';
    return 0;
}
