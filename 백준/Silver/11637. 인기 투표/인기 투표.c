#include <stdio.h>

int    main(void)
{
    int    i, j;
    int    n, m;
    int    cnt;
    int    tmp;
    int    max;
    int    sum;
    int    max_j;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        sum = max = cnt = 0;
        for (j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            if (max == tmp)
                cnt++;
            else if (max < tmp)
            {
                cnt = 0;
                max = tmp;
                max_j = j + 1;
            }
            sum += tmp;
        }
        if (cnt >= 1)
            printf("no winner\n");
        else if (max > sum / 2)
            printf("majority winner %d\n", max_j);
        else if (max <= sum / 2)
            printf("minority winner %d\n", max_j);
    }
}