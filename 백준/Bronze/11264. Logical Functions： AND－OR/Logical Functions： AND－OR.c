#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int (*t_logical)(int, int);

int AND(int a, int b) {
    return a & b;
}

int OR(int a, int b) {
    return a | b;
}

int output(double a) {
    return a >= 0;
}

int main(void) {
    int testCnt;
    const char *msg[] = {"false", "true"};
    const t_logical logicals[] = {&OR, &AND};

    scanf(" %d", &testCnt);
    while (testCnt-- > 0) {
        char name[4];
        double w1, w2, b;

        scanf(" %s %lf %lf %lf", name, &w1, &w2, &b);

        bool isCorrect = true;
        t_logical logical = logicals[name[0] == 'A'];

        for (int x1 = 0; x1 <= 1; x1++) {
            for (int x2 = 0; x2 <= 1; x2++) {
                if (logical(x1, x2) != output(x1 * w1 + x2 * w2 + b)) {
                    isCorrect = false;
                    x1 = x2 = 2;
                }
            }
        }

        printf("%s\n", msg[isCorrect]);
    }
    return 0;
}
