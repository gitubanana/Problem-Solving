#include <stdio.h>
#include <stdlib.h>

inline void swap(int *a, int *b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

bool selectionSort(int *arr, int size, int swapCnt) {
    for (int last = size - 1; last >= 1; last--) {
        int maxIdx = 0;

        for (int i = 1; i <= last; i++) {
            if (arr[maxIdx] < arr[i]) {
                maxIdx = i;
            }
        }

        if (maxIdx != last) {
            if (--swapCnt == 0) {
                fprintf(stdout, "%d %d\n", arr[last], arr[maxIdx]);
                return true;
            }
            swap(&arr[maxIdx], &arr[last]);
        }
    }
    return false;
}

int main(void) {
    int size;
    int swapCnt;
    fscanf(stdin, " %d %d", &size, &swapCnt);

    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        fscanf(stdin, " %d", &arr[i]);
    }

    if (!selectionSort(arr, size, swapCnt)) {
        fprintf(stdout, "-1\n");
    }
    free(arr);
    return 0;
}
