#include <stdio.h>
#include <stdbool.h>

int binarySearch(int dest) {
    int searchCnt;
    int left = 1, right = 50, mid, cmp, isOdd;

    if ((dest & 1) == 1) {
        isOdd = 1;
        searchCnt = 2;
    }
    else {
        isOdd = 0;
        searchCnt = 1;
    }

    while (left <= right) {
        mid = (left + right) / 2;
        cmp = mid * 2 - isOdd;

        if (cmp == dest)
            break;
        else if (cmp < dest)
            left = mid + 1;
        else
            right = mid - 1;

        searchCnt = searchCnt + 1;
    }
    return searchCnt;
}

int main(void) {
    int dest;

    while (true) {
        scanf(" %d", &dest);
        if (dest == 0)
            break;

        printf("%d\n", binarySearch(dest));
    }
    return 0;
}
