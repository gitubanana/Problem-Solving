#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

int main(void)
{
    int *arr, size;
    int i, start, sum;

    scanf(" %d", &size);
    if (size == 0)
        printf("0\n");
    else
    {
        arr = new int[size];
        for (i = 0; i < size; ++i)
            scanf(" %d", &arr[i]);
        std::sort(arr, arr + size);
    
        start = roundf(static_cast<float>(size) * 15 / 100);
        sum = 0;
        size -= start;
        for (i = start; i < size; ++i)
            sum += arr[i];
        printf("%.0f\n", roundf(static_cast<float>(sum) / (size - start)));
        delete[] arr;
    }
    return 0;
}
