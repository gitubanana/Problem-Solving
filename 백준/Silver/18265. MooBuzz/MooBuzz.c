#include <stdio.h>
#include <limits.h>

const int MIN_LEFT = 1;
const int MAX_RIGHT = INT_MAX - 1;

int countNumIn(int num, int end) {
    return end / num;
}

int countMooIn(int end) {
    return countNumIn(3, end)
            + countNumIn(5, end)
            - countNumIn(15, end);
}

int binarySearch(int nth) {
    long long left = MIN_LEFT;
    long long right = MAX_RIGHT;

    while (left <= right) {
        int mid = (left + right) / 2;
        int numberCnt = mid - countMooIn(mid);

        if (numberCnt == nth) {
            while (mid % 3 == 0 || mid % 5 == 0) {
                mid--;
            }
            return mid;
        }

        if (numberCnt > nth) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    int nth;

    scanf(" %d", &nth);
    printf("%d\n", binarySearch(nth));
    return 0;
}
