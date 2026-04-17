#include <stdio.h>
#include <stdlib.h>

void    do_the_thing(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        arr[i] = arr[i + 1] - arr[i];
        i++;
    }
}

void    print_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
        printf("%d,", arr[i++]);
    printf("%d", arr[size - 1]);
}

void    print_ans(int *arr, int size, int cnt)
{
    int    i;
    
    i = 0;
    while (i < cnt)
    {
        do_the_thing(arr, size);
        size--;
        i++;
    }
    print_arr(arr, size);
}

int    main(void)
{
    int    i;
    int    n;
    int    k;
    int    *arr;
    
    i = 0;
    scanf("%d %d", &n, &k);
    arr = malloc(sizeof(int) * n);
    while (i < n - 1)
        scanf("%d,", &arr[i++]);
    scanf("%d", &arr[n - 1]);
    print_ans(arr, n, k);
    free(arr);
}