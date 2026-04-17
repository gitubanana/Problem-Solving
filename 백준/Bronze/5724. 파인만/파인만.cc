#include <stdio.h>
#include <math.h>

int main(void) {
    while (true) {
        int n;

        fscanf(stdin, " %d", &n);
        if (n == 0) {
            break;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += pow(i, 2);
        }

        fprintf(stdout, "%d\n", ans);
    }
    return 0;
}
