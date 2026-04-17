#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#define MAX 50000

int binary_search(int *arr, int size, int to_find)
{
    int left, right, mid;

    left = 0;
    right = size - 1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (to_find == arr[mid])
            return (mid);
        else if (to_find < arr[mid])
            right = mid - 1;
        else
            left = mid + 1; 
    }
    return (-1);
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a > *(int *)b);
}

int    main(void)
{
    int i, test_cnt;
    int *arr, size;
    int to_find, ask_cnt;

    scanf("%d", &test_cnt);
    while (test_cnt--)
    {
        scanf("%d", &size);
        arr = malloc(sizeof(int) * size);
        for (i = 0; i < size; i++)
            scanf("%d", &arr[i]);
        qsort(arr, size, sizeof(int), cmp);
        scanf("%d", &ask_cnt);
        while (ask_cnt--)
        {
            scanf("%d", &to_find);
            printf("%d\n", binary_search(arr, size, to_find) != -1);
        }
        free(arr);
    }
    return (0);
}