#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    int testCnt;
    int times[3];

    std::cin >> testCnt;
    while (testCnt--)
    {
        int unsolvedCnt = 0;
        for (int i = 0; i < 3; ++i)
        {
            std::cin >> times[i];
            if (times[i] == -1)
            {
                times[i] = 1000;
                ++unsolvedCnt;
            }
        }

        int i = 0;
        while (i < 2)
        {
            if (times[i] > times[i + 1])
                break ;
            ++i;
        }

        ans += (i == 2 && unsolvedCnt != 3);
    }

    std::cout << ans << '\n';
    return (0);
}
