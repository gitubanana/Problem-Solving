#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n;

    std::cin >> n;

    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        ans += (n / i) - (i - 1);
    }

    std::cout << ans << '\n';
    return (0);
}
