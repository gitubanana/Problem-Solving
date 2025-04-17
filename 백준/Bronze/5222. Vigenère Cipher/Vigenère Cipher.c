#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define KEY_SIZE 1001
#define PLAINTEXT_SIZE 100001
#define FIRST_LETTER 'A'
#define LETTER_COUNT 26

void vigenereChipher(char text[PLAINTEXT_SIZE], char key[KEY_SIZE]) {
    int keyLength = strlen(key);

    for (int i = 0; text[i]; i++) {
        int shiftCnt = key[i % keyLength] - FIRST_LETTER;
        int shiftFromStart = (text[i] - FIRST_LETTER + shiftCnt) % LETTER_COUNT;

        text[i] = FIRST_LETTER + shiftFromStart;
    }
}

int main(void) {
    int testCnt;
    char key[KEY_SIZE];
    char text[PLAINTEXT_SIZE];

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        scanf(" %s %s", key, text);
        vigenereChipher(text, key);
        printf("Ciphertext: %s\n", text);
    }
    return 0;
}
