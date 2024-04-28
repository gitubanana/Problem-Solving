#include <iostream>
#include <climits>

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
        dp[i] = INT_MAX;
    }

    for (int buyCnt = 1; buyCnt <= size; ++buyCnt)
    {
        for (int one = 1; one <= buyCnt; ++one)
        {
            dp[buyCnt] = std::min(dp[buyCnt], dp[buyCnt - one] + price[one]);
        }
    }

    std::cout << dp[size] << '\n';
    return (0);
}
