#include <iostream>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int64_t p, t;

        std::cin >> p >> t;
        std::cout << p + t / 4 - t / 7 << '\n';
    }
    return (0);
}
