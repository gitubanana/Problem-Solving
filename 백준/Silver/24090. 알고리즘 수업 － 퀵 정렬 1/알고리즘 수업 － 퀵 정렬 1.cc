#include <stdio.h>
#include <exception>

int swapCnt;

void swap(int &a, int &b) {
    if (--swapCnt == 0) {
        const int arr[] = {a, b};
        throw arr;
    }

    int tmp = a;

    a = b;
    b = tmp;
}

void quickSort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }

    int pivot = arr[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot) {
            swap(arr[j], arr[++i]);
        }
    }

    if (i + 1 != end) {
        swap(arr[end], arr[i + 1]);
    }

    quickSort(arr, start, i);
    quickSort(arr, i+2, end);
}

int main(void) {
    int *arr, size;

    scanf(" %d %d", &size, &swapCnt);
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        scanf(" %d", &arr[i]);
    }

    try {
        quickSort(arr, 0, size - 1);
        printf("-1\n");
    }
    catch(const int arr[]) {
        printf("%d %d\n", arr[0], arr[1]);
    }

    delete[] arr;
    return 0;
}
