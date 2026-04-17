#include <stdio.h>

int main() {
    char str[700001];

    for (int t = 1; fgets(str, sizeof(str), stdin) && str[0] != '0'; t++) {
        printf("Case %d: Sorting... done!\n", t);
    }
    return 0;
}