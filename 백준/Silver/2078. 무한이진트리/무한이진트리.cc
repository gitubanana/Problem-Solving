#include <stdio.h>

int main(void) {
    int a, b;
    int left = 0, right = 0;

    scanf(" %d %d", &a, &b);
    while (!(a == 1 && b == 1)) {
        if (a > b) {
            int cnt = a / b - (a % b == 0);

            left += cnt;
            a -= b * cnt;;
        } else {
            int cnt = b / a - (b % a == 0);

            right += cnt;
            b -= a * cnt;
        }
    }

    printf("%d %d\n", left, right);
    return 0;
}
//    (1 1)
// (2 1)   
//    (3 1)
// (3 4)
