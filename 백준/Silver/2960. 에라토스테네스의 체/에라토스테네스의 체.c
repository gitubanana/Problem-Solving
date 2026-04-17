#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#define ERASED -1

void    init_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = i + 2;
}

int strainer_of_Eratosthenes(int *arr, int size, int *erase_cnt)
{
    int i;
    int min, ans;

    for (i = 0; i < size; i++)
    {
        if (arr[i] != ERASED)
        {
            min = arr[i]; break ;
        }
    }
    ans = min;
    for (i = 0; i < size; i++)
    {
        if (*erase_cnt == 0)
            break ;
        if (arr[i] != ERASED && arr[i] % min == 0)
        {
            ans = arr[i]; arr[i] = ERASED; (*erase_cnt)--;
        }
    }
    return (ans);
}

int get_ans(int *arr, int size, int erase_cnt)
{
    int ans;

    ans = 2;
    init_arr(arr, size);
    while (erase_cnt > 0)
        ans = strainer_of_Eratosthenes(arr, size, &erase_cnt);
    return (ans);
}

int    main(void)
{
    int size, erase_cnt;
    int arr[1000];

    scanf("%d %d", &size, &erase_cnt);
    size--;
    printf("%d", get_ans(arr, size, erase_cnt));
    return (0);
}
