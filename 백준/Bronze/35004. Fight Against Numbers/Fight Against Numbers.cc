#include <stdio.h>

void reverseBits(int *ptr) {
    int last = 31;
    for (; last >= 0; last--) {
        if (*ptr & (1 << last)) {
            break;
        }
    }

    int reversed = 0;
    for (int left = last, right = 0; left >= right; left--, right++) {
        reversed |= (*ptr & (1 << right)) << (left - right);
        reversed |= (*ptr & (1 << left)) >> (left - right);
    }

    *ptr = reversed;
}

inline void subtractOne(int *ptr) {
    // ptr의 마지막 비트는 항상 1 
    *ptr ^= 1;
}

int main() {
    int n;
    int move = 0;

    scanf(" %d", &n);
    do {
        reverseBits(&n);
        subtractOne(&n);
        move++;
    } while (n != 0);

    printf("%d\n", move);
    return 0;
}