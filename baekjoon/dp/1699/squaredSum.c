#include <stdio.h>
#include <math.h>
#include <limits.h>
#define MAX 100000
#define DP_SIZE 100001
#define GET_MIN(a, b) (a) > (b) ? (b) : (a)

int dp[DP_SIZE];

int main(void)
{
    dp[1] = 1;
    for (int n = 2; n <= MAX; ++n)
    {
        int beSquared = 1;

        dp[n] = INT_MAX;
        while (1)
        {
            int squared = beSquared * beSquared;
            if (squared > n)
                break ;

            dp[n] = GET_MIN(dp[n], 1 + dp[n - squared]);
            ++beSquared;
        }
    }

    int toFind;

    scanf("%d", &toFind);
    printf("%d\n", dp[toFind]);
    return (0);
}
