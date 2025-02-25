#include <stdio.h>
#include <stdlib.h>

enum e_idx {
    Y = 1,
    X
};

int main(void) {
    int *deltas[3];
    int ySize, xSize, qCnt;

    fscanf(stdin, " %d %d %d", &ySize, &xSize, &qCnt);

    deltas[Y] = static_cast<int *>(calloc(sizeof(int), ySize + 1));
    deltas[X] = static_cast<int *>(calloc(sizeof(int), xSize + 1));
    while (qCnt-- > 0) {
        int i, j, delta;

        fscanf(stdin, " %d %d %d", &i, &j, &delta);
        deltas[i][j] += delta;
    }

    for (int y = 1; y <= ySize; y++) {
        for (int x = 1; x <= xSize; x++) {
            fprintf(stdout, "%d ", deltas[Y][y] + deltas[X][x]);
        }
        fprintf(stdout, "\n");
    }

    free(deltas[Y]);
    free(deltas[X]);
    return 0;
}
