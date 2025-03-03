#include <stdio.h>

const int MAX_SIZE = 300;

int size;
bool M[2][MAX_SIZE][MAX_SIZE];

int countOnes() {
    int cnt = 0;

    for (int aY = 0; aY < size; aY++) {
        for (int bX = 0; bX < size; bX++) {
            for (int j = 0; j < size; j++) {
                if (M[0][aY][j] & M[1][j][bX]) {
                    ++cnt;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main(void) {
    fscanf(stdin, " %d", &size);
    for (int i = 0; i < 2; i++) {
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                char ch;
    
                fscanf(stdin, " %c", &ch);
                M[i][y][x] = (ch == '1');
            }
        }
    }

    fprintf(stdout, "%d\n", countOnes());
    return 0;
}
