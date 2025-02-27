#include <stdio.h>

const int BIT_COUNT = 32;

int main(void) {
    int num;
    int i = 0;

    fscanf(stdin, " %d", &num);
    for (; i < BIT_COUNT; i++) {
        if (num & (1 << i)) {
            break;
        }
    }

    fprintf(stdout, "%d\n", BIT_COUNT - i - 1);
    return 0;
}
