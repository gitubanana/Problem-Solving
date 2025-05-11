#include <stdio.h>
#include <string.h>
#define MAX_SIZE 51

enum e_space {
    OK = '.',
    CONSTRUCTION = 'X'
};

void jumpMin(int dp[MAX_SIZE], char path[MAX_SIZE], int maxJump, int pathLen) {
    int jump;
    int cur = 0;

    do {
        for (jump = maxJump; jump >= 1; jump--) {
            int next = cur + jump;

            if (next < pathLen && path[next] == OK) {
                dp[next] = dp[cur] + 1;
                cur = next;
                break;
            }
        }
    } while (jump != 0);
}

int main(void) {
    int dayCnt;
    int dp[MAX_SIZE];
    char path[MAX_SIZE];

    scanf(" %d", &dayCnt);
    for (int day = 1; day <= dayCnt; day++) {
        int pathLen;
        int maxJump;

        scanf(" %d %d %s", &pathLen, &maxJump, path);

        memset(dp, 0, sizeof(dp));
        jumpMin(dp, path, maxJump + 1, pathLen);

        printf("Day #%d\n", day);
        printf("%d %d\n", pathLen, maxJump);
        printf("%s\n", path);
        printf("%d\n\n", dp[pathLen - 1]);
    }
    return 0;
}
