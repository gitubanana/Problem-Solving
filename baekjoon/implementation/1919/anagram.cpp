#include <iostream>

const int MAX = 1000;
const int ALPHA_SIZE = 26;

char str[MAX + 1];
int alphaCnt[ALPHA_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> str;
    for (int i = 0; str[i]; ++i)
        ++alphaCnt[str[i] - 'a'];

    std::cin >> str;
    for (int i = 0; str[i]; ++i)
        --alphaCnt[str[i] - 'a'];

    int ans = 0;
    for (int i = 0; i < ALPHA_SIZE; ++i)
        ans += std::abs(alphaCnt[i]);

    std::cout << ans << '\n';
    return (0);
}
