#include <stdio.h>
#include <stdlib.h>

void    scan_score(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
        scanf("%d", &arr[i++]);
}

int    cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

void    print_ans(int *arr, int size, int class)
{
    int    i;
    int    max_gap;
    
    i = -1;
    max_gap = 0;
    qsort(arr, size, sizeof(int), cmp);
    while (++i < size - 1)
        if (max_gap < arr[i] - arr[i + 1])
            max_gap = arr[i] - arr[i + 1];
    printf("Class %d\n", class);
    printf("Max %d, Min %d, Largest gap %d\n", arr[0], arr[size - 1], max_gap);
}

int    main(void)
{
    int    i;
    int    n;
    int    m;
    int    *arr;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d", &m);
        arr = malloc(sizeof(int) * m);
        scan_score(arr, m);
        print_ans(arr, m, i + 1);
        i++;
    }
    free(arr);
}