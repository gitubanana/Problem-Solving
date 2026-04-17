#include <stdio.h>
#include <stdlib.h>
#define ARR_INPUT(arr, size) \
    for (int i = 0; i < (size); i++) \
        scanf(" %d", (arr)+i);

int perimeterOf(int *ws, int *hs, int size) {
    int p = 0;

    for (int i = 0; i <= size; i++) {
        p += ws[i]*2;
        p += abs(hs[i]-hs[i+1]);
    }
    return p;
}

int main() {
    int testCnt;

    scanf(" %d", &testCnt);
    while (testCnt--) {
        int size;
        scanf(" %d", &size);

        int *ws = reinterpret_cast<int *>(malloc(sizeof(int)*(size+2)));
        int *hs = reinterpret_cast<int *>(malloc(sizeof(int)*(size+2)));

        ARR_INPUT(ws+1, size)
        ARR_INPUT(hs+1, size)
        ws[0] = ws[size+1] = hs[0] = hs[size+1] = 0;

        printf("%d\n", perimeterOf(ws, hs, size));

        free(ws);
        free(hs);
    }

    return 0;
}

