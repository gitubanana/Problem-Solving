#include <iostream>
#include <algorithm>

int    main(void)
{
    int    *arr;
    int    i, total_size, size1, size2;
    
    scanf(" %d %d", &size1, &size2);
    total_size = size1 + size2;
    arr = new int[total_size];
    for (i = 0; i < total_size; ++i)
        scanf(" %d", &arr[i]);
    std::sort(arr, arr + total_size);
    for (i = 0; i < total_size; ++i)
        printf("%d ", arr[i]);
    return (0);
}