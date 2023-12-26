#include <iostream>

const int   MAX = 1001;
const int   DIVISOR = 10007;

int dp[MAX][MAX];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int N, R;

    std::cin >> N >> R;
    for (int n = 1; n <= N; ++n)
    {
        dp[n][0] = 1;
        for (int r = 1; r <= R; ++r)
        {
            if (n == r)
                dp[n][r] = 1;
            else
                dp[n][r] = ((dp[n - 1][r - 1] % DIVISOR)
                            + (dp[n - 1][r] % DIVISOR)) % DIVISOR;
        }
    }

    std::cout << dp[N][R] << '\n';
    return (0);
}
