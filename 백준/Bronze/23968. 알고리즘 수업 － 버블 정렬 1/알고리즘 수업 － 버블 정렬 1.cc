#include <stdio.h>
#include <stdlib.h>

inline void swap(int *a, int *b) {
    int tmp = *a;

    *a = *b;
    *b = tmp;
}

bool bubbleSort(int *arr, int size, int swapCnt) {
    for (int last = size - 1; last >= 1; last--) {
        for (int i = 0; i < last; i++) {
            if (arr[i] > arr[i + 1]) {
                if (--swapCnt == 0) {
                    fprintf(stdout, "%d %d\n", arr[i + 1], arr[i]);
                    return true;
                }
                swap(&arr[i], &arr[i + 1]);
            }
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

    if (!bubbleSort(arr, size, swapCnt)) {
        fprintf(stdout, "-1\n");
    }

    free(arr);
    return 0;
}
