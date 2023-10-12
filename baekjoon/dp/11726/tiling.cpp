#include <iostream>

const int   MAX = 1000;

int dp[MAX + 1];

int main(void)
{
    int n;

    scanf(" %d", &n);

    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    printf("%d\n", dp[n] % 10007);
    return (0);
}
