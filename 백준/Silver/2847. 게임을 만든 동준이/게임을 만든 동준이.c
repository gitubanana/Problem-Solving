#include <stdio.h>
#include <stdlib.h>

void    print_fix_cnt(int *arr, int size)
{
    int    i;
    int    j;
    int    fix;
    
    i = size - 1;
    while (i > 0)
    {
        if (arr[i] <= arr[i - 1])
        {
            j = 1;
            while (arr[i] <= arr[i - 1] - j)
                j++;
            arr[i - 1] -= j;
            fix += j;
        }
        i--;
    }
    printf("%d", fix);
}

int    main(void)
{
    int    i;
    int    n;
    int    error_cnt;
    int    *arr;
    
    i = 0;
    error_cnt = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &arr[i++]);   
    print_fix_cnt(arr, n);
    free(arr);
}