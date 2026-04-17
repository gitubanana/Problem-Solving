#include <stdio.h>

int    main(void)
{
    int    a, b;
    int    n, m;
    
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d %d", &a, &b);
            printf("%d %d\n", a + b, a * b);
        }
    }
}