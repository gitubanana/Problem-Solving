#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n, size, cnt, ans = 0;
    std::string str;

    std::cin >> n >> size >> str;
    cnt = 0;
    for (int i = 1; i < size - 1; ++i)
    {
        if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I')
        {
            ++cnt, ++i;
            if (cnt == n)
                --cnt, ++ans;
        }
        else
            cnt = 0;
    }

    std::cout << ans << '\n';

    return (0);
}
