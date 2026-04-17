#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    error_and_exit(char *msg)
{
        perror(msg);
        exit(1);
}

void    free_2D_arr(int **arr, int height)
{
        for (int i = 0; i < height; i++)
                free(arr[i]);
        free(arr);
}

int     **init_2D_arr(int height, int width)
{
        int     **ret;

        ret = malloc(sizeof(int *) * height);
        if (!ret)
                error_and_exit("malloc error");
        memset(ret, 0, sizeof(int *) * height);
        for (int i = 0; i < height; i++)
        {
                ret[i] = malloc(sizeof(int) * width);
                if (!ret[i])
                {
                        free_2D_arr(ret, height);
                        error_and_exit("malloc error");
                }
        }
        return (ret);
}

void    take_input_2D_arr(int **arr, int height, int width)
{
        for (int i = 0, j; i < height; i++)
                for (j = 0; j < width; j++)
                        scanf("%d", &arr[i][j]);
}

void    print_sum(int **arr)
{
        int     test_cnt, i, j, sum;
        int     start_row, start_col, end_row, end_col;

        scanf("%d", &test_cnt);
        while (test_cnt--)
        {
                scanf("%d %d %d %d",
                                &start_row, &start_col, &end_row, &end_col);
                start_row--; start_col--;
                end_row--; end_col--;
                for (i = start_row, sum = 0; i <= end_row; i++)
                        for (j = start_col; j <= end_col; j++)
                                sum += arr[i][j];
                printf("%d\n", sum);
        }
}

int     main(void)
{
        int     **arr, height, width;

        scanf("%d %d", &height, &width);
        arr = init_2D_arr(height, width);
        take_input_2D_arr(arr, height, width);
        print_sum(arr);
        free_2D_arr(arr, height);
        return (0);
}