#include <stdio.h>
#include <string.h>

const int SIZE = 4 + 1;

int main(void) {
    int n, ans = 0;
    char cmp[SIZE], jinheo[SIZE];

    fscanf(stdin, " %s %d", jinheo, &n);
    for (int i = 0; i < n; i++) {
        fscanf(stdin, " %s", cmp);
        ans += !strcmp(jinheo, cmp);
    }

    fprintf(stdout, "%d\n", ans);
    return 0;
}
