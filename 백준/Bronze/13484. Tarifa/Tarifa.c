#include <stdio.h>

int    main(void)
{
    int    n;
    int    tmp, sum;
    int    per_month;
    
    scanf("%d %d", &per_month, &n);
    sum = (n + 1) * per_month;
    while (n--)
    {
        scanf("%d", &tmp);
        sum -= tmp;
    }
    printf("%d", sum);
}