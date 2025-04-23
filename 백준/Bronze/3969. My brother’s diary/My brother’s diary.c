#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 1001
#define LETTER_COUNT 26
#define FIRST_LETTER 'A'
#define NO_KEY '!'

int findKey(char text[MAX_SIZE]) {
    static int count[LETTER_COUNT];
    int max = 0;
    char encryptedE;

    memset(count, 0, sizeof(count));
    for (int i = 0; text[i]; i++) {
        if (!isupper(text[i])) {
            continue;
        }

        int cIdx = text[i] - FIRST_LETTER;

        if (max < ++count[cIdx]) {
            max = count[cIdx];
            encryptedE = text[i];
        } else if (max == count[cIdx]) {
            encryptedE = NO_KEY;
        }
    }

    if (encryptedE == NO_KEY) {
        return NO_KEY;
    }
    return (LETTER_COUNT + encryptedE - 'E') % LETTER_COUNT;
}

void caesarDecrypt(char text[MAX_SIZE], int key) {
    for (int i = 0; text[i]; i++) {
        if (!isupper(text[i])) {
            continue;
        }

        text[i] = FIRST_LETTER + (text[i] - FIRST_LETTER + LETTER_COUNT - key) % LETTER_COUNT;
    }
}

int main(void) {
    char nl;
    int testCnt;
    char text[MAX_SIZE];

    scanf(" %d%c", &testCnt, &nl);
    for (int t = 0; t < testCnt; t++) {
        gets(text);

        int key = findKey(text);
        if (key == NO_KEY) {
            printf("NOT POSSIBLE\n");
            continue;
        }

        caesarDecrypt(text, key);
        printf("%d %s\n", key, text);
    }
    return 0;
}
