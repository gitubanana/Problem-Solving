#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define LETTER_COUNT 26
#define FIRST_LETTER 'a'
#define TEXT_SIZE 252

void caesarDecrypt(char *text, int shift) {
    for (int i = 0; text[i]; i++) {
        if (!islower(text[i])) {
            continue;
        }

        int shiftFromStart = (text[i] - FIRST_LETTER + LETTER_COUNT - shift) % LETTER_COUNT;

        text[i] = FIRST_LETTER + shiftFromStart;
    }
}

int main(void) {
    char text[TEXT_SIZE];

    while (true) {
        int m, d, y;

        scanf(" %d %d %d", &m, &d, &y);
        if (m == 0) {
            break;
        }

        scanf(" %[^\n]", text);
        caesarDecrypt(text, (m + d + y) % 25 + 1);
        printf("%s\n", text);
    }
    return 0;
}
