#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) \
            (a) > (b) ? (a) : (b)

int main(void) {
    int *arr;
    int arrSize, windowSize;

    scanf(" %d %d", &arrSize, &windowSize);

    arr = malloc(sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++) {
        scanf(" %d", arr + i);
    }

    int sum = 0;
    for (int i = 0; i < windowSize; i++) {
        sum += arr[i];
    }

    int ans = sum;
    if (windowSize != arrSize)
    {
        int plusIdx = windowSize;
        do {
            sum += arr[plusIdx];
            sum -= arr[(arrSize + plusIdx - windowSize) % arrSize];
            ans = MAX(ans, sum);
            plusIdx = (plusIdx + 1) % arrSize;
        } while (plusIdx != windowSize);
    }

    printf("%d\n", ans);
    free(arr);
    return 0;
}
