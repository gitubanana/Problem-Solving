#include <stdio.h>
#include <stdlib.h>

int    tmp[1000000];

void    merge(int *arr, int left, int mid, int right)
{
    int    l_idx, r_idx, c_idx, t_idx;
    
    r_idx = mid + 1;
    l_idx = c_idx = left;
    
    while (l_idx <= mid && r_idx <= right)
    {
        if (arr[l_idx] < arr[r_idx])
            tmp[c_idx++] = arr[l_idx++];
        else
            tmp[c_idx++] = arr[r_idx++];
    }
    
    if (l_idx > mid)
        for (t_idx = r_idx; t_idx <= right; t_idx++)
            tmp[c_idx++] = arr[t_idx];
    else
        for (t_idx = l_idx; t_idx <= mid; t_idx++)
            tmp[c_idx++] = arr[t_idx];
    
    for (t_idx = left; t_idx <= right; t_idx++)
        arr[t_idx] = tmp[t_idx];
}

void    merge_sort(int *arr, int left, int right)
{
    int    mid;
    
    if (left == right)
        return ;
    mid = (left + right) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void    print_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
        printf("%d\n", arr[i++]);
}

int    main(void)
{
    int    i;
    int    n;
    int    *arr;
    
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    i = 0;
    while (i < n)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    merge_sort(arr, 0, n - 1);
    print_arr(arr, n);
    free(arr);
}