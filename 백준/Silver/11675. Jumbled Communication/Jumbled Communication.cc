#include <stdio.h>

const int MAX_BIT = 7;

int decode(int encoded) {
    int decoded = encoded & 1;

    for (int bit = 1; bit <= MAX_BIT; bit++) {
        decoded |= ((decoded >> bit - 1 & 1) ^ (encoded >> bit & 1)) << bit;
    }
    return decoded;
}

int main() {
    int size;

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) {
        int encoded;

        scanf(" %d", &encoded);
        printf("%d ", decode(encoded));
    }
    return 0;
}