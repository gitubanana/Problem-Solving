#include <stdio.h>

const int MAX_NUM = 1e6;

int cnt[MAX_NUM + 1];

void moveToNext(int &cur, int dx) {
    while (cnt[cur] == 0) {
        cur += dx;
    }
}

inline int min(int a, int b) {
    return a > b ? b : a;
}

int twoPointer(void) {
    int left = 1;
    int right = MAX_NUM;
    int ans = (1LL << 31) - 1;

    moveToNext(left, 1);
    moveToNext(right, -1);
    while (left <= right) {
        ans = min(ans, left+right);

        cnt[left]--;
        moveToNext(left, 1);

        cnt[right]--;
        moveToNext(right, -1);
    }
    return ans;
}

int main(void) {
    int size;

    scanf(" %d", &size);
    for (int i = 0; i < size; i++) {
        int num;

        scanf(" %d", &num);
        ++cnt[num];
    }

    printf("%d\n", twoPointer());
    return 0;
}
