#include <stdio.h>
#include <stdlib.h>

void    scan(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
        scanf("%d", &arr[i++]);
}

void    print_ans(int *len, int l_size, int *cost)
{
    int                   i;
    int                   min;
    unsigned long long    sum;
    
    i = 0;
    min = cost[0];
    sum = 0;
    while (i < l_size)
    {
        if (cost[i] < min)
            min = cost[i];
        sum += (unsigned long long)len[i] * (unsigned long long)min;
        i++;
    }
    printf("%llu", sum);
}

int    main(void)
{
    int    n;
    int    *len;
    int    *cost;
    
    scanf("%d", &n);
    len = malloc(sizeof(int) * (n - 1));
    cost = malloc(sizeof(int) * n);
    if (!len || !cost)
        return (1);
    scan(len, n - 1);
    scan(cost, n);
    print_ans(len, n - 1, cost);
    free(len);
    free(cost);
    return (0);
}