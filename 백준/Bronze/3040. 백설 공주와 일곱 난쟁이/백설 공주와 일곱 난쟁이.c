#include <stdio.h>

void    print_ans(int *arr, int size, int sum)
{
    int    flag;
    int    i, j, k;
    
    flag = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum - 100)
            {
                arr[i] = arr[j] = 0;
                flag = 1;
                break;
            }
        }
        if (flag)
            break;
    }
    for (k = 0; k < size; k++)
        if (arr[k] != 0)
            printf("%d\n", arr[k]);
}

int    main(void)
{
    int    i;
    int    sum;
    int    arr[9];
    
    sum = 0;
    for (i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    print_ans(arr, 9, sum);
}
