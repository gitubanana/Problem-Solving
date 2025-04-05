#include <stdio.h>
#include <stdlib.h>

int insertionSort(int *arr, int size, int swapCnt) {
    for (int start = 1; start < size; start++) {
        int cmp = arr[start];
        int down = start - 1;

        for (; down >= 0; down--) {
            if (arr[down] < cmp) {
                break;
            }

            if (--swapCnt == 0) {
                return fprintf(stdout, "%d\n", arr[down]);
            }
            arr[down + 1] = arr[down];
        }

        if (down + 1 != start) {
            if (--swapCnt == 0) {
                return fprintf(stdout, "%d\n", cmp);
            }
            arr[down + 1] = cmp;
        }
    }

    return 0;
}

int main(void) {
    int size;
    int swapCnt;
    fscanf(stdin, " %d %d", &size, &swapCnt);

    int *arr = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++){
        fscanf(stdin, " %d", &arr[i]);
    }

    if (!insertionSort(arr, size, swapCnt)) {
        fprintf(stdout, "-1\n");
    }
    free(arr);
    return 0;
}
