#include <stdio.h>
#define MIN(a, b) a > b ? b : a

const int MAX_SIZE = 101;

int main(void) {
    int testCnt;
    char str[MAX_SIZE];

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int cnt[] = {0, 0};

        scanf(" %s", str);
        for (int i = 0; str[i]; i++) {
            cnt[str[i] == 'a']++;
        }

        printf("%d\n", MIN(cnt[0], cnt[1]));
    }
    return 0;
}
