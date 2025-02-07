#include <stdio.h>
#include <stdlib.h>

inline void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

bool selectionSort(int *arr, int size, int swapCnt) {
    for (int last = size - 1; last >= 1; last--) {
        int maxIdx = 0;
        for (int i = 1; i <= last; i++) {
            if (arr[maxIdx] < arr[i]) {
                maxIdx = i;
            }
        }

        if (last != maxIdx) {
            swap(&arr[last], &arr[maxIdx]);
            if (--swapCnt == 0) {
                return true;
            }
        }
    }
    return false;
}

int main(void) {
    int size, swapCnt;
    fscanf(stdin, " %d %d", &size, &swapCnt);

    int *arr = static_cast<int *>(malloc(sizeof(int) * size));
    for (int i = 0; i < size; i++) {
        fscanf(stdin, " %d", &arr[i]);
    }

    if (selectionSort(arr, size, swapCnt)) {
        for (int i = 0; i < size; i++) {
            fprintf(stdout, "%d ", arr[i]);
        }
    } else {
        fprintf(stdout, "-1");
    }

    fprintf(stdout, "\n");
    free(arr);
    return 0;
}
