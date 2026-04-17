#include <stdio.h>
#include <stdlib.h>

int    get_cnt_of_num(int *arr, int arr_size, int to_find)
{
    int    cnt;
    
    cnt = 0;
    while (arr_size--)
        if (arr[arr_size] == to_find)
            cnt++;
    return (cnt);
}

int    main(void)
{
    int    *arr;
    int    arr_size;
    int    to_find;
    
    scanf("%d", &arr_size);
    arr = malloc(sizeof(int) * arr_size);
    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &to_find);
    printf("%d", get_cnt_of_num(arr, arr_size, to_find));
    free(arr);
    return (0);
}