#include <stdio.h>

void    init_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
        arr[i++] = 0;
}

void    print_ans(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
        if (arr[i++] == 0)
            printf("%d\n", i);
}

int    main(void)
{
    int    i;
    int    tmp;
    int    arr[30];
    
    i = -1;
    init_arr(arr, 30);
    while (++i < 28)
    {
        scanf("%d", &tmp);
        arr[tmp - 1] = 1;
    }
    print_ans(arr, 30);
}