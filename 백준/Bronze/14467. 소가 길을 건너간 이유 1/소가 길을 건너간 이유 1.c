#include <stdio.h>
#include <stdlib.h>

void    init(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        arr[i] = 2;
        i++;
    }
}

int    main(void)
{
    int    i;
    int    n;
    int    idx;
    int    tmp;
    int    cnt;
    int    *arr;
    
    i = 0;
    cnt = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * 10);
    init(arr, 10);
    while (i < n)
    {
        scanf("%d %d", &idx, &tmp);
        if (arr[idx - 1] == 2)
            arr[idx - 1] = tmp;
        else if (arr[idx - 1] != tmp)
        {
            arr[idx - 1] = tmp;
            cnt++;
        }
        i++;
    }
    printf("%d", cnt);
}