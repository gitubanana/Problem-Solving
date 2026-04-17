#include <stdio.h>
#include <stdlib.h>

int    cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int    main(void)
{
    int    i;
    int    n, k;
    int    *arr;
    
    scanf("%d %d", &n, &k);
    arr = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), cmp);
    printf("%d", arr[k - 1]);
}