#include <stdio.h>

void    insertion_sort(int *arr, int size)
{
    int    i;
    int    j;
    int    tmp;
    
    i = 1;
    while (i < size)
    {
        j = i;
        tmp = arr[j];
        while (--j >= 0 && tmp < arr[j])
        {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
        }
        i++;
    }
}

void    print_score(int *arr, int size)
{
    insertion_sort(arr, size);
    if (arr[3] - arr[1] >= 4)
        printf("KIN\n");
    else
        printf("%d\n", arr[1] + arr[2] + arr[3]);
}

int    main(void)
{
    int    i;
    int    j;
    int    n;
    int    arr[5];
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        j = 0;
        while (j < 5)
            scanf("%d", &arr[j++]);
        print_score(arr, 5);
        i++;
    }
}