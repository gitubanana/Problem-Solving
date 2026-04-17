#include <stdio.h>
#include <string.h>

// Two versions of DOORS cannot be installed in succession
enum e_idx {
    OTHER,
    DOORS,
    CHOICE_CNT
};

const int MAX_SIZE = 40;
const int INIT_VALUE = -1;

int size;
int dp[MAX_SIZE][CHOICE_CNT];

int dfs(int cur=0, bool prevWasDoors=false) {
    if (cur == size) {
        return 1;
    }

    int &ret = dp[cur][prevWasDoors];
    if (ret != INIT_VALUE) {
        return ret;
    }

    int next = cur + 1;

    ret = dfs(next, false);
    if (!prevWasDoors) {
        ret += dfs(next, true);
    }
    return ret;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 1; t <= testCnt; t++) {
        scanf(" %d", &size);
        memset(dp, INIT_VALUE, sizeof(dp));
        printf("Scenario %d:\n%d\n\n", t, dfs());
    }
    return 0;
}
