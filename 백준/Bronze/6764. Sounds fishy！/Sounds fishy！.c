#include <stdio.h>

int    is_ascending(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] >= arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int    is_descending(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] <= arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int    is_identical(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] != arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int    main(void)
{
    int    i;
    int    arr[4];
    char    *ans;
    
    i = 0;
    while (i < 4)
        scanf("%d", &arr[i++]);
    if (is_ascending(arr, 4))
        ans = "Fish Rising";
    else if (is_descending(arr, 4))
        ans = "Fish Diving";
    else if (is_identical(arr, 4))
        ans = "Fish At Constant Depth";
    else
        ans = "No Fish";
    printf("%s", ans);
}