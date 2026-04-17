#include <stdio.h>

const int NUMBER_COUNT = 3;
const int BIT_COUNT = 4;
const int PW_LENGTH = 4;
const int LSB = (1 << BIT_COUNT) - 1;

int lengthOf(int num, int base=10) {
    int len = 0;

    while (num > 0) {
        len++;
        num /= base;
    }
    return len;
}

int main() {
    int pw = 0;

    for (int i = 0; i < NUMBER_COUNT; i++) {
        int num;

        scanf(" %d", &num);
        pw <<= BIT_COUNT;
        pw |= num & LSB;
    }

    int pwLength = lengthOf(pw) + (pw == 0);
    for (int padding = pwLength; padding < PW_LENGTH; padding++) {
        printf("0");
    }
    printf("%d\n", pw);
    return 0;
}