#include <stdio.h>

int    main(void)
{
    int           i, n;
    long long    dp[91];

    dp[0] = 0;
    dp[1] = 1;
    scanf("%d", &n);
    for (i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    printf("%lld", dp[n]);
}