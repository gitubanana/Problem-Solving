#include <stdio.h>
#include <stdlib.h>

void    print_sum(int *arr, int size)
{
    int    i;
    int    j;
    long long    sum;
    
    i = 0;
    sum = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            sum += llabs(arr[i] - arr[j]);
            j++;
        }
        i++;
    }
    printf("%lld", sum);
}

int    main(void)
{
    int    i;
    int    n;
    int    *arr;
    
    i = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &arr[i++]);
    print_sum(arr, n);
    free(arr);
}