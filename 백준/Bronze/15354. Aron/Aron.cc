#include <stdio.h>

int main(void) {
    char nl;
    int size;
    int groupCnt = 0;
    int groupColor = 0;

    scanf(" %d%c", &size, &nl);
    for (int i = 0; i < size; i++) {
        int cmp = getchar();
        nl = getchar();

        if (groupColor != cmp) {
            groupCnt++;
            groupColor = cmp;
        }
    }

    printf("%d\n", groupCnt + 1);
    return 0;
}
