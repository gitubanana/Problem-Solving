#include <stdio.h>

int    arr[8];

void    back_tracking(int v, int n, int depth, int m)
{
    int    i;
    
    if (depth == m)
    {
        for (i = 0; i < m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for (i = 1; i <= n; i++)
    {
        arr[depth] = i;
        back_tracking(i, n, depth + 1, m);
    }
}

int    main(void)
{
    int    n, m;
    
    scanf("%d %d", &n, &m);
    back_tracking(1, n, 0, m);
}