#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    std::cin >> str;

    int ans;

    if (str.substr(0, 2) == "10")
        ans = 10 + std::stoi(str.substr(2));
    else
        ans = (str[0] - '0') + std::stoi(str.substr(1));

    std::cout << ans << '\n';
    return (0);
}
