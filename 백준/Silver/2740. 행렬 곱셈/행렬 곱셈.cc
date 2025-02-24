#include <stdio.h>

const int MAX_SIZE = 100;

int aYsize, aXsize;
int A[MAX_SIZE][MAX_SIZE];

int bYsize, bXsize;
int B[MAX_SIZE][MAX_SIZE];

int main(void) {
    fscanf(stdin, " %d %d", &aYsize, &aXsize);
    for (int y = 0; y < aYsize; y++) {
        for (int x = 0; x < aXsize; x++) {
            fscanf(stdin, " %d", &A[y][x]);
        }
    }

    fscanf(stdin, " %d %d", &bYsize, &bXsize);
    for (int y = 0; y < bYsize; y++) {
        for (int x = 0; x < bXsize; x++) {
            fscanf(stdin, " %d", &B[y][x]);
        }
    }

    for (int aY = 0; aY < aYsize; aY++) {
        for (int bX = 0; bX < bXsize; bX++) {
            int result = 0;

            for (int i = 0; i < aXsize; i++) {
                result += A[aY][i] * B[i][bX];
            }
            fprintf(stdout, "%d ", result);
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
