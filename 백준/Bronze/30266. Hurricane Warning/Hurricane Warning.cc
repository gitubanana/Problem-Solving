#include <stdio.h>

int main(void) {
    int testCnt;
    char str[11];

    scanf(" %d", &testCnt);
    for (int t = 1; t <= testCnt; t++) {
        int peopleCnt;
        int isInformed = 0;

        scanf(" %d %s", &peopleCnt, str);
        for (int i = 0; str[i]; i++) {
            isInformed |= 1 << (str[i] - 'A');
        }

        int informedCnt = 0;
        for (int p = 0; p < peopleCnt; p++) {
            scanf(" %s", str);
            for (int i = 0; str[i]; i++) {
                if (isInformed & (1 << (str[i] - 'A'))) {
                    informedCnt++;
                    break;
                }
            }
        }

        printf("Data Set %d:\n%d\n\n", t, informedCnt);
    }
    return 0;
}
