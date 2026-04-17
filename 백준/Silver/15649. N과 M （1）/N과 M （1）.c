#include <stdio.h>

int    arr[8];
int    visited[9];

void    back_tracking(int n, int depth, int m)
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
        if (visited[i] == 0)
        {
            visited[i] = 1;
            arr[depth] = i;
            back_tracking(n, depth + 1, m);
            visited[i] = 0;
        }
    }
}

int    main(void)
{
    int    n, m;
    
    scanf("%d %d", &n, &m);
    back_tracking(n, 0, m);
}