#include <stdio.h>
#define END vCnt

const int MAX_V = 2e5 + 1;
const int NOT_VISITED = -2;
const int IMPOSSIBLE = -1;

int vCnt;
int dp[MAX_V];
int nexts[MAX_V];

void dfs(int cur) {
    if (cur == END) {
        return;
    }

    int &curDp = dp[cur];
    int &next = nexts[cur];
    if (curDp != NOT_VISITED) {
        return;
    }

    curDp = IMPOSSIBLE;
    dfs(next);
    if (dp[next] != IMPOSSIBLE) {
        curDp = dp[next] + 1;
    }
}

int main(void) {
    scanf(" %d", &vCnt);
    for (int v = 1; v <= vCnt; v++) {
        scanf(" %d", &nexts[v]);
        dp[v] = NOT_VISITED;
    }

    dp[END] = 0;
    for (int v = 1; v <= vCnt; v++) {
        dfs(v);
        printf("%d\n", dp[v]);
    }
    return 0;
}
