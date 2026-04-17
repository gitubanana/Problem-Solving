#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 5e5 + 1;
const int ROOT = 1;

int swapped;
int size, realSize;
int arr[MAX_SIZE];

inline void swap(int &a, int &b) {
    int tmp = a;

    a = b;
    b = tmp;

    if (--swapped == 0) {
        for (int i = 1; i <= realSize; i++) {
            printf("%d ", arr[i]);
        }
        exit(0);
    }
}

void heapify(int cur) {
    int left = cur * 2;
    int right = left + 1;
    int smaller = left;

    if (left > size) {
        return;
    }

    if (right <= size && arr[right] < arr[smaller]) { 
        smaller = right;
    }

    if (arr[smaller] < arr[cur]) {
        swap(arr[smaller], arr[cur]); 
        heapify(smaller); 
    } 
}

void buildMinHeap(void) {
    for (int i = size / 2; i >= ROOT; i--) {
        heapify(i);
    }
}

void heapSort(void) {
    buildMinHeap();
    while (size > ROOT) { 
        swap(arr[ROOT], arr[size--]);
        heapify(ROOT); 
    } 
}

int main() {
    scanf(" %d %d", &size, &swapped);
    for (int i = 1; i <= size; i++) {
        scanf(" %d", &arr[i]);
    }

    realSize = size;
    heapSort();
    printf("-1\n");
    return 0;
}