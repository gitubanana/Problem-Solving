#include <stdio.h>

char    str[50][51];

void    scan_str(int n)
{
    int    i;
    
    for (i = 0; i < n; i++)
        scanf("%s", str[i]);
}

void    print_ans(int n, int m)
{
    int    i, j;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m / 2; j++)
            if (str[i][j] != '.')
                str[i][m - 1 - j] = str[i][j];
        for (j = 0; j < m / 2; j++)
            if (str[i][m - 1 - j] != '.')
                str[i][j] = str[i][m - 1 - j];
    }
    for (i = 0; i < n; i++)
        printf("%s\n", str[i]);
}

int    main(void)
{
    int    n, m;
    
    scanf("%d %d", &n, &m);
    scan_str(n);
    print_ans(n, m);
}