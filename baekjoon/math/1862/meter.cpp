#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    std::string str;

    std::cin >> str;
    for (int i = 0; str[i]; ++i)
    {
        int num = str[i] - '0';

        ans = ans * 9 + (num - (num > 4));
    }

    std::cout << ans << '\n';
    return (0);
}
