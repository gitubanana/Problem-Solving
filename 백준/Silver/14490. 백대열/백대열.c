#include <stdio.h>

int     get_gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return (a + b);
}

int    main(void)
{
    int    gcd;
    int    num[2];
    
    scanf("%d:%d", &num[0], &num[1]);
    gcd = get_gcd(num[0], num[1]);
    printf("%d:%d", num[0] / gcd, num[1] / gcd);
}