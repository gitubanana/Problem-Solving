#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
    int *tmp = malloc(sizeof(int) * (right - left + 1));

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int idx = 0;
    int L = left;
    int R = mid + 1;

    while (L <= mid && R <= right) {
        if (arr[L] < arr[R]) {
            tmp[idx] = arr[R++];
        } else {
            tmp[idx] = arr[L++];
        }
        idx++;
    }

    if (L > mid) {
        for (; R <= right; R++) {
            tmp[idx++] = arr[R];
        }
    } else {
        for (; L <= mid; L++) {
            tmp[idx++] = arr[L];
        }
    }

    for (int i = left; i <= right; i++) {
        arr[i] = tmp[i - left];
    }
}

int getMinBox(int candyCount, int *boxes, int boxCount) {
    int i = 0;

    mergeSort(boxes, 0, boxCount - 1);
    for (; i < boxCount && candyCount > 0; i++) {
        candyCount -= boxes[i];
    }
    return i;
}

int main(void) {
    int testCount;

    scanf(" %d", &testCount);
    while (testCount-- > 0) {
        int candyCount, boxCount;
        scanf(" %d %d", &candyCount, &boxCount);

        int *boxes = malloc(sizeof(int) * boxCount);

        for (int i = 0; i < boxCount; i++) {
            int ySize, xSize;

            scanf(" %d %d", &ySize, &xSize);
            boxes[i] = ySize * xSize;
        }

        printf("%d\n", getMinBox(candyCount, boxes, boxCount));
        free(boxes);
    }

    return (0);
}