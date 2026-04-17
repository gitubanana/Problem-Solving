#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100000

void    print_max_arr(int *arr, int size, int *dp)
{
        int     i;
        int     max;

        dp[0] = arr[0];
        for (i = 1; i < size; i++)
        {
                if (dp[i - 1] + arr[i] > arr[i])
                        dp[i] = dp[i - 1] + arr[i];
                else
                        dp[i] = arr[i];
        }
        for (i = 0, max = INT_MIN; i < size; i++)
                if (max < dp[i])
                        max = dp[i];
        printf("%d", max);
}

int     main(void)
{
        int     i;
        int     *arr, size;
        int     dp[MAX];

        scanf("%d", &size);
        arr = malloc(sizeof(int) * size);
        if (!arr)
                return (perror(""), 1);
        for (i = 0; i < size; i++)
                scanf("%d", &arr[i]);
        print_max_arr(arr, size, dp);
        return (0);
}