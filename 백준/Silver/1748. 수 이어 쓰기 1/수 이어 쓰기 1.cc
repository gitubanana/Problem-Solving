#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    std::string str;

    std::cin >> str;

    int powOfTen = 1;
    for (int len = 1; len < str.size(); ++len)
    {
        ans += 9 * powOfTen * len;
        powOfTen *= 10;
    }

    ans += (std::atoi(str.c_str()) - powOfTen + 1) * str.size();
    std::cout << ans << '\n';
    return (0);
}
