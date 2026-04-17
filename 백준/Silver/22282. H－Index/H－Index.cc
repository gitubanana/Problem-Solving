#include <stdio.h>
#include <algorithm>

int size;

inline void swap(int &a, int &b) {
    int tmp = a;

    a = b;
    b = tmp;
}

void quickSort(int *arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int &pivot = arr[left];
    int L = left + 1;
    int R = right;

    while (true) {
        while (L <= right && arr[L] <= pivot) {
            L++;
        }

        while (R > left && arr[R] >= pivot) {
            R--;
        }

        if (L > R) {
            break;
        }

        swap(arr[L], arr[R]);
    }

    swap(pivot, arr[R]);
    quickSort(arr, left, R - 1);
    quickSort(arr, R + 1, right);
}

int main(void) {
    int *arr;

    scanf(" %d", &size);
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        scanf(" %d", arr + i);
    }

    // quickSort(arr, 0, size - 1);
    std::sort(arr, arr + size);

    int i = 0;
    for (; i < size; i++) {
        if (arr[size - i - 1] < i + 1) {
            break;
        }
    }

    printf("%d\n", i);
    delete[] arr;
    return 0;
}
