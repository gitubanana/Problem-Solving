#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define COW_SIZE 3

enum e_idx {
    OW,
    O,
    W
};

int size;
long long ans;
long long dp[COW_SIZE];
char str[MAX_SIZE + 1];

void dfs(int cur) {
    if (!str[cur]) {
        return;
    }

    int next = cur + 1;
    char curCh = str[cur];

    dfs(next);

    switch (curCh)
    {
    case 'C':
        ans += dp[O] * dp[W];
        ans += dp[OW];
        break;
    case 'O':
        dp[O]++;
        break;
    case 'W':
        if (dp[O] > 0) {
            dp[OW] += dp[O] * dp[W];
            dp[O] = 0;
        }

        dp[W]++;
        break;
    }
}

int main(void) {
    scanf(" %d %s", &size, str);
    dfs(0);
    printf("%lld\n", ans);
    return (0);
}
