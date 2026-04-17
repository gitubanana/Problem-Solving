#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int    cmp(int a, int b)
{
    return (a - b);
}

int    count_same(int *arr, int size, int target, int (*cmp)(int, int))
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    while (i < size)
    {
        if (!cmp(target, arr[i]))
            cnt++;
        i++;
    }
    return (cnt);
}

int    main(void)
{
    int    i;
    int    date;
    int    *arr;
    int    result;
    
    i = 0;
    arr = (int *)malloc(sizeof(int) * 5);
    scanf("%d", &date);
    while (i < 5)
        scanf("%d", &arr[i++]);
    result = count_same(arr, 5, date, cmp) + '0';
    write(1, &result, 1);
}