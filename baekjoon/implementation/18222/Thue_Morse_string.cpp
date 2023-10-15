#include <iostream>
#include <vector>
#include <cmath>
#include <map>
// 1, 2, 4, 8, 16, 32, 64
// 0, 1, 2, 3, 4,   5,  6

typedef unsigned long long ull;

ull k;

int get_thue_morse(ull n)
{
    ull       bit = 1;
    int       depth = 0;
    const int num[] = {0, 1};

    while (n > 0)
    {
        n -= (bit << static_cast<int>(std::log2(n)));
        ++depth;
    }
    return (num[depth % 2]);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> k;
    std::cout << get_thue_morse(k - 1) << '\n';
    return (0);
}
