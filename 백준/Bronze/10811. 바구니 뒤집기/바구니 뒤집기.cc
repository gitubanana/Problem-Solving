#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void rev(int *arr, int size) {
    int half = size >> 1;

    for (int i=0; i<half; i++) {
        swap(&arr[i], &arr[size-i-1]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int size, revCnt;
    cin >> size >> revCnt;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i+1;
    }

    while (revCnt--) {
        int L, R;

        cin >> L >> R;
        --L, --R;
        rev(&arr[L], R-L+1);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}