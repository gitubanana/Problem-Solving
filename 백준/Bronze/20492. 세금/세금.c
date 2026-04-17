#include <stdio.h>

int    main(void)
{
    int    src;
    int    a;
    int    b;
    
    scanf("%d", &src);
    a = src - (src / 100 * 22);
    b = src - ((src / 100 * 20) / 100 * 22);
    printf("%d %d", a, b);
}