#include <stdio.h>

int    main(void)
{
    int    i;
    int    j;
    int    n;
    
    scanf("%d", &n);
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        while (n - j)
        {
            printf("*");
            j++;
        }
        printf("\n");
    }
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
            printf(" ");
        while (n - j)
        {
            printf("*");
            j++;
        }
        printf("\n");
    }
    return (0);
}