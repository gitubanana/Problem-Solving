#include <iostream>

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string a, b, c, d;

    std::cin >> a >> b >> c >> d;

    std::cout << std::atoll((a + b).c_str()) + std::atoll((c + d).c_str()) << '\n';
    return 0;
}
