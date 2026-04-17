#include <stdio.h>

int    is_divided(int *arr, int size, int aim)
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    while (i < size)
    {
        if (aim % arr[i] == 0)
            cnt++;
        i++;
    }
    if (cnt >= 3)
        return (1);
    else
        return (0);
}

void    print_ans(int *arr, int size)
{
    int    i;
    
    i = 1;
    while (1)
    {
        if (is_divided(arr, size, i))
            break;
        i++;
    }
    printf("%d", i);
}

int    main(void)
{
    int    i;
    int    arr[5];
    
    i = 0;
    while (i < 5)
        scanf("%d", &arr[i++]);
    print_ans(arr, 5);
}