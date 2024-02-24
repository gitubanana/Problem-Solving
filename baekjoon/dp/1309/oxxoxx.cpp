#include <iostream>

const int MAX = 100001;

int dp[MAX][3];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int cur = 2; cur <= size; ++cur)
    {
        dp[cur][0] = (dp[cur - 1][1] + dp[cur - 1][2]) % 9901;
        dp[cur][1] = (dp[cur - 1][0] + dp[cur - 1][2]) % 9901;
        dp[cur][2] = (dp[cur - 1][0] + dp[cur - 1][1] + dp[cur - 1][2]) % 9901;
    }

    std::cout << (dp[size][0] + dp[size][1] + dp[size][2]) % 9901 << '\n';
    return (0);
}
