#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LETTER_COUNT 26
#define FIRST_LETTER 'a'
#define KEY_SIZE 30001
#define PLAINTEXT_SIZE 30001

void vigenereChipher(char text[PLAINTEXT_SIZE], char key[KEY_SIZE]) {
    int keyLength = strlen(key);

    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            continue;
        }

        int shiftCnt = key[i % keyLength] - FIRST_LETTER + 1;
        int shiftFromStart = (text[i] - FIRST_LETTER + LETTER_COUNT - shiftCnt) % LETTER_COUNT;

        text[i] = FIRST_LETTER + shiftFromStart;
    }
}

int main(void) {
    char key[KEY_SIZE];
    char text[PLAINTEXT_SIZE];

    gets(text);
    gets(key);
    vigenereChipher(text, key);
    puts(text);
    return 0;
}
