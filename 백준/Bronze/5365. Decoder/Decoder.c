#include <stdio.h>
#include <string.h>
#define MAX_WORD_SIZE 32

int main(void) {
    int wordCnt;
    int prevLen = 1;
    char word[MAX_WORD_SIZE];

    scanf(" %d", &wordCnt);
    for (int i = 0; i < wordCnt; i++) {
        scanf(" %s", word);

        int curLen = strlen(word);

        printf("%c", curLen >= prevLen ? word[prevLen - 1] : ' ');
        prevLen = curLen;
    }
    printf("\n");
    return 0;
}
