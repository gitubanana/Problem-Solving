#include <stdio.h>
#include <stdlib.h>

int    get_size(int n)
{
    int    size;
    
    size = 0;
    while(n > 0)
    {
        n /= 2;
        size++;
    }
    return (size);
}

int    *change_to_2(int n)
{
    int    i;
    int    size;
    int    *arr;
    
    i = 0;
    size = get_size(n);
    arr = malloc(sizeof(int) * size);
    while (i < size)
    {
        arr[i] = n % 2;
        n /= 2;
        i++;
    }
    return (arr);
}

void    print_1(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        if (arr[i])
            printf("%d ", i);
        i++;
    }
}

int    main(void)
{
    int    i;
    int    t;
    int    n;
    int    *arr;
    
    i = 0;
    scanf("%d", &t);
    while (i < t)
    {
        scanf("%d", &n);
        arr = change_to_2(n);
        print_1(arr, get_size(n));
        free(arr);
        i++;
    }
}