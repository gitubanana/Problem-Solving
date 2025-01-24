#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int k;

bool mergeSort(int *arr, int left, int right, int *sorted) {
    if (left >= right) {
        return false;
    }

    int mid = (left + right) / 2;

    if (mergeSort(arr, left, mid, sorted)
        || mergeSort(arr, mid + 1, right, sorted)) {
        return true;
    }

    int i = 0;
    int L = left;
    int R = mid + 1;

    while (L <= mid && R <= right) {
        if (arr[L] < arr[R]) {
            sorted[i++] = arr[L++];
        } else {
            sorted[i++] = arr[R++];
        }
    }

    if (L <= mid) {
        while (L <= mid) {
            sorted[i++] = arr[L++];
        }
    } else {
        while (R <= right) {
            sorted[i++] = arr[R++];
        }
    }

    for (int j = left; j <= right; j++) {
        if (--k == 0) {
            printf("%-5d\n", sorted[j - left]);
            return true;
        }

        arr[j] = sorted[j - left];
    }

    return false;
}

int main(void) {
    int size;
    scanf(" %d %d", &size, &k);

    int *arr = malloc(sizeof(int) * size);
    int *sorted = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf(" %d", arr + i);
    }

    if (!mergeSort(arr, 0, size - 1, sorted)) {
        printf("%-5d\n", -1);
    }

    free(arr);
    free(sorted);
    return 0;
}
