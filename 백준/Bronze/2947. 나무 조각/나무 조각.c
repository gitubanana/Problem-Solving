#include <stdio.h>

void    swap(int *a, int *b)
{
    int    tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    print_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int    is_ascending(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size - 1)
    {
        if (arr[i] > arr[i + 1])
            return (0);
        i++;
    }
    return (1);
}

void    print_process(int *arr, int size)
{
    int    i;
    int    j;
    
    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - 1 - i)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                print_arr(arr, size);
            }
            j++;
        }
        if (is_ascending(arr, size))
            break;
        i++;
    }
}

int    main(void)
{
    int    i;
    int    arr[5];
    
    i = 0;
    while (i < 5)
        scanf("%d", &arr[i++]);
    print_process(arr, 5);
}