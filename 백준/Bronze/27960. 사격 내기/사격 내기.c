#include <stdio.h>
#include <ctype.h>
#define MAX_BUFFER_SIZE 16

char buffer[MAX_BUFFER_SIZE];

int nextInt(void) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);
    printf("%d\n", nextInt() ^ nextInt());
    return 0;
}
