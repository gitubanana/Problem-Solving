#include <iostream>
#include <cstring>

const int   MAX = 10000000;

int cnt[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    int num;
    int ans;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> num;
        ++cnt[num];
        if (cnt[num] == 2)
            ans = num;
    }
    std::cout << ans << '\n';
    return (0);
}
