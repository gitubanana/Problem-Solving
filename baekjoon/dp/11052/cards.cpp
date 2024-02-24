#include <iostream>

const int MAX = 1001;

int size;
int dp[MAX];
int price[MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 1; i <= size; ++i)
    {
        std::cin >> price[i];
    }

    for (int i = 1; i <= size; ++i)
    {
        for (int one = 1; one <= i; ++one)
        {
            dp[i] = std::max(dp[i], dp[i - one] + price[one]);
        }
    }

    std::cout << dp[size] << '\n';
    return (0);
}
