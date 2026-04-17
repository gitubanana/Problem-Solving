#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n, size, cnt, ans = 0;
    std::string str;

    std::cin >> n >> size >> str;
    for (int i = 1; i < size; ++i)
    {
        if (str[i - 1] == 'I')
        {
            cnt = 0;
            while (str[i] == 'O' && str[i + 1] == 'I')
            {
                i += 2;
                ++cnt;
                if (cnt == n)
                    --cnt, ++ans;
            }
        }
    }

    std::cout << ans << '\n';

    return (0);
}
