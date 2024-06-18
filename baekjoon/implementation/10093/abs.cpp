#include <iostream>

inline int getDiff(int small, int big)
{
    int diff = big - small - 1;
    return diff * (diff > 0);
}

int main(void)
{
    uint64_t small, big;

    std::cin >> small >> big;
    if (small > big)
        std::swap(small, big);

    std::cout << getDiff(small, big) << '\n';
    ++small, --big;
    while (small <= big)
    {
        std::cout << small << ' ';
        ++small;
    }
    std::cout << '\n';
    return (0);
}
