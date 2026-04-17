#include <stdio.h>

long long    gcd(long long a, long long b)
{
    while (a != 0 && b != 0)
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
    long long    a, b;
    
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a * b / gcd(a, b));
}