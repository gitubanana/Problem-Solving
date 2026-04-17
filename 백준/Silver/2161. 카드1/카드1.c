#include <stdio.h>
#include <stdlib.h>

void    init_1_to_n(int *arr, int n)
{
    int    i;
    
    i = 0;
    while (i < n)
    {
        arr[i] = i + 1;
        i++;
    }
}

void    change_cards(int *arr, int first, int last)
{
    int    i;
    int    tmp;
    
    i = first;
    tmp = arr[first];
    while (i < last - 1)
    {
        arr[i] = arr[i + 1];
        i++;
    }
    arr[last - 1] = tmp;
}


void    print_cards(int *arr, int size)
{
    int    i;
    
    i = 0;
    if (size == 1)
    {
        printf("%d ", 1);
        return ;
    }
    while (i < size)
    {
        printf("%d ", arr[i++]);
        change_cards(arr, i, size);
    }
}

int    main(void)
{
    int    n;
    int    *arr;
    
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    init_1_to_n(arr, n);
    print_cards(arr, n);
    free(arr);
}