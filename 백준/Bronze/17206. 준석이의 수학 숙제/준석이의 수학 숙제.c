#include <stdio.h>

int end;

int sumOfMultiplesOf(int num) {
    int difference = num;
    int elemCnt = end / num;
    int lastElem = elemCnt * num;

    return (num + lastElem) * elemCnt / 2;
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {

        scanf(" %d", &end);
        printf(
            "%d\n",
            sumOfMultiplesOf(3)
            + sumOfMultiplesOf(7)
            - sumOfMultiplesOf(21)
        );
    }
    return 0;
}
