#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int a, b, c;

    std::cin >> a >> b >> c;
    std::cout << std::max(a + c, b) << '\n';
    return (0);
}
