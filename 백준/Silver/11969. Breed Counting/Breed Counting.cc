#include <stdio.h>

const int BREED_COUNT = 3;
const int MAX_SIZE = 1e5;

int breeds[MAX_SIZE + 1][BREED_COUNT + 1];

int main(void) {
    int size, qCnt;

    scanf(" %d %d", &size, &qCnt);
    for (int i = 1; i <= size; i++) {
        int cur;

        scanf(" %d", &cur);
        for (int b = 1; b <= BREED_COUNT; b++) {
            breeds[i][b] = breeds[i - 1][b];
        }
        breeds[i][cur]++;
    }

    for (int q = 0; q < qCnt; q++) {
        int start, end;

        scanf(" %d %d", &start, &end);
        for (int b = 1; b <= BREED_COUNT; b++) {
            printf("%d ", breeds[end][b] - breeds[start - 1][b]);
        }
        printf("\n");
    }
    return 0;
}
