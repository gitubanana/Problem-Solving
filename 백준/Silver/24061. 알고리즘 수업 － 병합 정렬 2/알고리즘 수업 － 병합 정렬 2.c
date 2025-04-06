#include <stdio.h>
#include <stdlib.h>

int mergeSort(int *arr, int left, int right, int *pSwapCnt) {
    static int tmp[500000];

    if (left >= right) {
        return 0;
    }

    int mid = (left + right) / 2;
    if (mergeSort(arr, left, mid, pSwapCnt) || mergeSort(arr, mid + 1, right, pSwapCnt)) {
        return 1;
    }

    int i = 0;
    int L = left;
    int R = mid + 1;

    while (L <= mid && R <= right) {
        if (arr[L] < arr[R]) {
            tmp[i++] = arr[L++];
        } else {
            tmp[i++] = arr[R++];
        }
    }

    while (L <= mid) {
        tmp[i++] = arr[L++];
    }

    while (R <= right) {
        tmp[i++] = arr[R++];
    }

    i = 0;
    while (left <= right) {
        arr[left++] = tmp[i++];
        if (--(*pSwapCnt) == 0) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int size, swapCnt;
    fscanf(stdin, " %d %d", &size, &swapCnt);

    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        fscanf(stdin, " %d", &arr[i]);
    }

    if (!mergeSort(arr, 0, size - 1, &swapCnt)) {
        fprintf(stdout, "-1");
    } else {
        for (int i = 0; i < size; i++) {
            fprintf(stdout, "%d ", arr[i]);
        }
    }
    fprintf(stdout, "\n");
    free(arr);
    return 0;
}
