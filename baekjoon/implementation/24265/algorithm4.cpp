#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    uint64_t n;

    std::cin >> n;
    std::cout << n * (n - 1) / 2 << '\n';
    std::cout << '2' << '\n';
    return (0);
}
