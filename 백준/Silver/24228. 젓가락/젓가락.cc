#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    uint64_t n, r;

    std::cin >> n >> r;
    std::cout << (n + 2*r) - 1 << '\n';
    return (0);
}
