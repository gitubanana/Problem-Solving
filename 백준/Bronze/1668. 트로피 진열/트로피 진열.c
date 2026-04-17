#include <stdio.h>
#include <stdlib.h>

void    print_ans(int *arr, int size)
{
    int    i;
    int    tmp[2] = {0, };
    int    left;
    int    right;
    
    i = 0;
    left = 0;
    right = 0;
    while (i < size)
    {
        if (arr[i] > tmp[0])
        {
            tmp[0] = arr[i];
            left++;
        }
        if (arr[size - 1 - i] > tmp[1])
        {
            tmp[1] = arr[size - 1 - i];
            right++;
        }
        i++;
    }
    printf("%d %d", left, right);
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
    print_ans(arr, n);
}