#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_BUFFER_SIZE 1024

// struct bit field
typedef struct {
    int bits : 8;
} int8;

char buffer[MAX_BUFFER_SIZE];

int nextInt(void) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

void print8bits(int8 num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num.bits & (1 << i)) != 0);
    }
}

void printNumAndBits(int8 num) {
    printf("%d = ", num.bits);
    print8bits(num);
    printf("\n");
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    while (true) {
        int8 a = {nextInt()};
        int8 b = {nextInt()};
        if (a.bits == 0 && b.bits == 0) {
            break;
        }

        int8 aMinus = {-a.bits};
        int8 bMinus = {-b.bits};
        int8 diff = {a.bits - b.bits};

        printNumAndBits(a);
        printNumAndBits(b);
        printNumAndBits(aMinus);
        printNumAndBits(bMinus);
        printNumAndBits(diff);
        printf("\n");
    }
    return 0;
}
