#include <stdio.h>

int main(void) {
    int A, B, C;

    fscanf(stdin, " %d %d %d", &A, &B, &C);
    for (int x = 1; x <= 10; x++) {
        bool isEmpty = true;

        for (int y = 1; y <= 10; y++) {
            if (A * x + B * y == C) {
                isEmpty = false;
                fprintf(stdout, "%d ", y);
            }
        }

        if (isEmpty) {
            fprintf(stdout, "0");
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
