#include <stdio.h>

int    main(void)
{
    int    a;
    int    b;
    
    scanf("%d %d", &a, &b);
    printf("%d", a * (b - 1) + 1);
}