#include <iostream>
#include <vector>

const int64_t MAX = 4 * 1e9;

inline bool isPrime(int64_t num)
{
    if (num <= 1)
        return (false);

    for (int64_t divisor = 2; divisor * divisor <= num; ++divisor)
    {
        if (num % divisor == 0)
            return (false);
    }
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int64_t num;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> num;
        while (!isPrime(num))
        {
            ++num;
        }
        std::cout << num << '\n';
    }
    return (0);
}
