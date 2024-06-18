#include <iostream>

inline int64_t getDiff(int64_t small, int64_t big)
{
    if (small == big)
        return (0);

    int64_t diff = big - small - 1;
    return diff * (diff > 0);
}

int main(void)
{
    uint64_t small, big;

    std::cin >> small >> big;
    if (small > big)
    {
        small ^= big;
        big ^= small;
        small ^= big;
    }

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
