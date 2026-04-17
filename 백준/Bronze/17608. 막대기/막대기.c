#include <stdio.h>
#include <stdlib.h>

void    print_see(int *arr, int size)
{
    int    i;
    int    cnt;
    int    max;
    
    i = 0;
    cnt = 0;
    max = 0;
    while (i < size)
    {
        if (max < arr[size - 1 - i])
        {
            max = arr[size - 1 - i];
            cnt++;
        }
        i++;
    }
    printf("%d", cnt);
}

int    main(void)
{
    int    i;
    int    n;
    int    *arr;
    
    i = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &arr[i++]);
    print_see(arr, n);
    free(arr);
}