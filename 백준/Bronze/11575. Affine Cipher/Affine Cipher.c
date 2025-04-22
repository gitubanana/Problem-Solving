#include <stdio.h>
#define MAX_SIZE 1000001
#define FIRST_LETTER 'A'
#define MODULA 26

void affineCipher(char text[MAX_SIZE], int a, int b) {
    for (int i = 0; text[i]; i++) {
        int x = text[i] - FIRST_LETTER;

        text[i] = FIRST_LETTER + (a * x + b) % MODULA;
    }
}

int main(void) {
    int testCnt;
    char text[MAX_SIZE];

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int a, b;

        scanf(" %d %d %s", &a, &b, text);
        affineCipher(text, a, b);
        printf("%s\n", text);
    }
    return 0;
}
