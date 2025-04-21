#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 251
#define LETTOR_COUNT 26

int main(void) {
    char nl;
    int testCnt;

    scanf(" %d%c", &testCnt, &nl);
    for (int t = 0; t < testCnt; t++) {
        int count[LETTOR_COUNT];
        char cyphertext[MAX_SIZE];
        char ans = '!';
        int max = 0;

        gets(cyphertext);
        memset(count, 0, sizeof(count));
        for (int i = 0; cyphertext[i]; i++) {
            if (!islower(cyphertext[i])) {
                continue;
            }

            int alphaIdx = cyphertext[i] - 'a';
            if (max < ++count[alphaIdx]) {
                max = count[alphaIdx];
                ans = cyphertext[i];
            } else if (max == count[alphaIdx]) {
                ans = '?';
            }
        }

        printf("%c\n", ans);
    }
    return 0;
}
