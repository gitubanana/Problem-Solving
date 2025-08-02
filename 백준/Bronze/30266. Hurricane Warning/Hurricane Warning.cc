#include <stdio.h>
#include <string.h>

int main(void) {
    int testCnt;
    char str[11];
    bool isInformed[26];

    scanf(" %d", &testCnt);
    for (int t = 1; t <= testCnt; t++) {
        int peopleCnt;

        scanf(" %d %s", &peopleCnt, str);
        memset(isInformed, false, sizeof(isInformed));
        for (int i = 0; str[i]; i++) {
            isInformed[str[i] - 'A'] = true;
        }

        int informedCnt = 0;
        for (int p = 0; p < peopleCnt; p++) {
            scanf(" %s", str);
            for (int i = 0; str[i]; i++) {
                if (isInformed[str[i] - 'A']) {
                    informedCnt++;
                    break;
                }
            }
        }

        printf("Data Set %d:\n%d\n\n", t, informedCnt);
    }
    return 0;
}
