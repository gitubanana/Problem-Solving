#include <iostream>

const int SIZE = 10;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int num;
        int sum = 0;
        int inputCnt = SIZE;

        while (inputCnt--)
        {
            std::cin >> num;
            sum += num * (num & 1);
        }

        std::cout << '#' << t << ' ' << sum << '\n';
    }
    return (0);
}
