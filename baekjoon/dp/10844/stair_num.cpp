#include <iostream>

const int   MAX = 101;
const int   DIVISOR = 1e9;

int dp[MAX][10];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;

    for (int i = 1; i <= 9; ++i)
        dp[1][i] = 1;

    for (int s = 2; s <= size; ++s)
    {
        dp[s][0] = dp[s - 1][1];
        for (int n = 1; n <= 8; ++n)
        {
            dp[s][n] = dp[s - 1][n - 1] + dp[s - 1][n + 1];
            dp[s][n] %= DIVISOR;
        }
        dp[s][9] = dp[s - 1][8] % DIVISOR;
    }

    long long ans = 0;
    for (int i = 0; i <= 9; ++i)
        ans += dp[size][i];

    std::cout << (ans % DIVISOR) << '\n';
    return (0);
}