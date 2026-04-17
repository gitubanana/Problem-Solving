#include <stdio.h>
#include <stdlib.h>

int    cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void    print_ans(int *arr, int size)
{
    int    i;
    int    j;
    int    cnt;
    
    i = 0;
    cnt = 0;
    qsort(arr, size, sizeof(int), cmp);
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (arr[i] * 2 == arr[j])
                cnt++;
            j++;
        }
        i++;
    }
    printf("%d\n", cnt);
}

int    main(void)
{
    int    size;
    int    *arr;
    
    arr = malloc(sizeof(int) * 15);
    while (1)
    {
        size = 0;
        scanf("%d", &arr[size]);
        if (arr[size++] == -1)
            break;
        while (1)
        {
            scanf("%d", &arr[size]);
            if (arr[size] == 0)
                break;
            size++;
        }
        print_ans(arr, size + 1);
    }
    free(arr);
}