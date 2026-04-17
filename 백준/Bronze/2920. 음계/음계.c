#include <stdio.h>
#include <stdlib.h>

int    cmp(int a, int b)
{
    return (a - b);
}

int    is_ascending(int *arr, int size, int (*cmp)(int, int))
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (cmp(arr[i], arr[i + 1]) >= 0)
            return (0);
        i++;
    }
    return (1);
}

int    is_descending(int *arr, int size, int (*cmp)(int, int))
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (cmp(arr[i], arr[i + 1]) <= 0)
            return (0);
        i++;
    }
    return (1);
}

int    main(void)
{
    int    i;
    int    *arr;
    char   *msg;
    
    i = 0;
    arr = (int *)malloc(sizeof(int) * 8);
    while (i < 8)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    if (is_ascending(arr, 8, cmp))
        msg = "ascending";
    else if (is_descending(arr, 8, cmp))
        msg = "descending";
    else
        msg = "mixed";
    printf("%s", msg);
}