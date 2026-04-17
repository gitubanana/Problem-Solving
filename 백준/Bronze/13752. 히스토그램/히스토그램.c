#include <stdio.h>

void    print_histogram(int m)
{
    int    j;
    
    j = 0;
    while (j < m)
    {
        printf("=");
        j++;
    }
    printf("\n");
}

int    main(void)
{
    int    i;
    int    n;
    int    m;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d", &m);
        print_histogram(m);
        i++;
    }
}