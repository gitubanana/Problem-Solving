#include <stdio.h>
#include <string.h>

const int MAX_SIZE = 256;

char str[MAX_SIZE];
char ans[MAX_SIZE];

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int l, r;

        scanf(" %s %d %d", str, &l, &r);

        ans[0] = 0;
        strncat(ans, str, l);
        strcat(ans, str+r);

        printf("%s\n", ans);
    }
    return 0;
}
