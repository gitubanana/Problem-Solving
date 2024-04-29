#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    uint64_t x, m;

    std::cin >> x >> m;
    std::cout << x * (m + 1) << '\n';
    return (0);
}
