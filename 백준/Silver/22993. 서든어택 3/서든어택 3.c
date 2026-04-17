#include <stdio.h>
#include <stdlib.h>

int    cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void    print_ans(int *arr, int size, long long me)
{
    int    i;
    char    *ans;
    
    i = 0;
    qsort(arr, size, sizeof(int), cmp);
    while (i < size)
    {
        if (me <= arr[i])
            break;
        else
            me += arr[i];
        i++;
    }
    if (me > arr[size - 1])
        ans = "Yes";
    else
        ans = "No";
    printf("%s", ans);
}

int    main(void)
{
    int    i;
    int    n;
    long long    me;
    int    *arr;
    
    i = 0;
    scanf("%d", &n);
    scanf("%lld", &me);
    arr = malloc(sizeof(int) * (n - 1));
    while (i < n - 1)
        scanf("%d", &arr[i++]);
    print_ans(arr, n - 1, me);
    free(arr);
}