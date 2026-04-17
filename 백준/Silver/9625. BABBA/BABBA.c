#include <stdio.h>

int    main(void)
{
    int    n;
    int    a = 1, b = 0, tmp;
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        tmp = a;
        a = b;
        b = tmp + b;
    }
    printf("%d %d", a, b);
}