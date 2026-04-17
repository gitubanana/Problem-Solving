#include <stdio.h>
#include <stdlib.h>

void    insertion_sort(int *arr, int size)
{
    int    i, j;
    int    tmp;
    
    for (i = 1; i < size; i++)
    {
        tmp = arr[(j = i)];
        while (--j >= 0 && arr[j] < tmp)
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void    print_ans(int *arr, int size)
{
    insertion_sort(arr, size);
    printf("%d\n", arr[2]);
}

int    main(void)
{
    int    i;
    int    n;
    int    arr[10];
    
    scanf("%d", &n);
    while (n--)
    {
        for (i = 0; i < 10; i++)
            scanf("%d", &arr[i]);
        print_ans(arr, 10);
    }
}