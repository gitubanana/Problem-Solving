#include <stdio.h>
#include <string.h>

const int SIZE = 2;

char map[SIZE][SIZE + 1];
const char *dirs = "SENW";
const char *names[] = {"T", "F", "Lz", NULL};
const char *strs[] = {".OP.", "I..P", "O..P"};

void rotate(void) {
    static char temp[SIZE][SIZE + 1];

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            temp[y][x] = map[SIZE - x - 1][y];
        }
    }

    memcpy(map, temp, sizeof(temp));
}

bool isEqualTo(const char *str) {
    int i = 0;

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (str[i++] != map[y][x]) {
                return false;
            }
        }
    }
    return true;
}

const char *findAnswer() {
    for (int i = 0; names[i]; i++) {
        if (isEqualTo(strs[i])) {
            return names[i];
        }
    }
    return "?";
}

int main(void) {
    char dir;
    int rotateCnt;

    fscanf(stdin, " %c", &dir);
    while (dirs[rotateCnt] != dir) {
        rotateCnt++;
    }

    for (int y = 0; y < SIZE; y++) {
        fscanf(stdin, " %s", map[y]);
    }

    while (rotateCnt-- > 0) {
        rotate();
    }
    fprintf(stdout, "%s\n", findAnswer());
    return 0;
}
