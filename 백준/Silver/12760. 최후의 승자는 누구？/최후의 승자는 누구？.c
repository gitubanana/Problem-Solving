#include <stdio.h>
#include <stdlib.h>

int    arr[100][100];

int    cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

void    print_ans(int n, int m)
{
    int    i, j;
    int    max;
    int    *point;
    
    point = calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        qsort(arr[i], m, sizeof(int), cmp);
    for (i = 0; i < m; i++)
    {
        max = 0;
        for (j = 0; j < n; j++)
            if (max < arr[j][i])
                max = arr[j][i];
        for (j = 0; j < n; j++)
            if (max == arr[j][i])
                point[j]++;
    }
    max = 0;
    for (i = 0; i < n; i++)
        if (max < point[i])
            max = point[i];
    for (i = 0; i < n; i++)
        if (max == point[i])
            printf("%d ", i + 1);
}

int    main(void)
{
    int    i, j, n;
    int    card_cnt;
    
    scanf("%d %d", &n, &card_cnt);
    for (i = 0; i < n; i++)
        for (j = 0; j < card_cnt; j++)
            scanf("%d", &arr[i][j]);
    print_ans(n, card_cnt);
}