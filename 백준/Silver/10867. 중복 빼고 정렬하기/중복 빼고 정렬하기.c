#include <stdio.h>
#include <stdlib.h>

int    cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void    print_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    qsort(arr, size, sizeof(int), cmp);
    while (i < size)
    {
        if (i == 0)
            printf("%d ", arr[i]);
        else if (arr[i] != arr[i - 1])
            printf("%d ", arr[i]);
        i++;
    }
}

int    main(void)
{
    int    i;
    int    n;
    int    *arr;
    
    i = 0;
    scanf("%d\n", &n);
    arr = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &arr[i++]);
    print_arr(arr, n);
    free(arr);
}