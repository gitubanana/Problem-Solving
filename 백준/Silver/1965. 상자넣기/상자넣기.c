#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 5010
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int nextInt(char buffer[MAX_BUFFER_SIZE]) {
    static int index = -1;
    int ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

int countMaxPutBox(int *arr, int size) {
    int maxCnt = 0;
    int *dp = (int *)calloc(size, sizeof(int));

    for (int from = 0; from < size - 1; from++) {
        for (int to = from + 1; to < size; to++) {
            if (arr[from] >= arr[to]) {
                continue;
            }

            maxCnt = MAX(
                maxCnt,
                dp[to] = MAX(dp[to], dp[from] + 1)
            );
        }
    }

    free(dp);
    return maxCnt + 1;
}

int main(void) {
    char buffer[MAX_BUFFER_SIZE];
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    int size = nextInt(buffer);
    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = nextInt(buffer);
    }

    printf("%d\n", countMaxPutBox(arr, size));
    free(arr);
    return 0;
}
