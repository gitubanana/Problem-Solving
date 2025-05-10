#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main(void) {
    int n;
    fscanf(stdin, " %d", &n);

    ll *dp = (ll *)malloc(sizeof(ll) * (n + 1));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int half = i / 2;

        dp[i] = (i & 1) * dp[half] * dp[half];
        for (int p = 0; p < half; p++) {
            dp[i] += 2 * dp[p] * dp[i - p - 1];
        }
    }

    printf("%lld\n", dp[n]);
    free(dp);
    return 0;
}
