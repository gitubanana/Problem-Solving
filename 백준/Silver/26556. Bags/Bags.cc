#include <stdio.h>
#include <functional>
#include <algorithm>

class Array {
public:
    int *arr;
    int size;

    Array(int size) : arr(new int[size]), size(size) {
        for (int i = 0; i < size; i++) {
            fscanf(stdin, " %d", &arr[i]);
        }
        std::sort(arr, arr + size, std::less<int>());
    }

    ~Array() {
        delete[] arr;
    }

    inline int &operator[](int index) {
        return arr[index];
    }
};

int goal;
int ans;

bool backTracking(Array &arr, int sum=0, int addCnt=0, int depth=0) {
    if (sum > goal) {
        return false;
    }

    if (sum == goal) {
        ans = addCnt;
        return true;
    }

    if (depth == arr.size) {
        return false;
    }

    const int nextDepth = depth + 1;
    if (backTracking(arr, sum, addCnt, nextDepth)
        || backTracking(arr, sum + arr[depth], addCnt + 1, nextDepth)) {
        return true;
    }

    return false;
}

int main(void) {
    int testCnt;

    fscanf(stdin, " %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int size;
        fscanf(stdin, " %d", &size);

        Array arr(size);
        fscanf(stdin, " %d", &goal);
        if (backTracking(arr)) {
            fprintf(stdout, "%d\n", ans);
        } else {
            fprintf(stdout, "Not possible\n");
        }
    }
    return 0;
}
