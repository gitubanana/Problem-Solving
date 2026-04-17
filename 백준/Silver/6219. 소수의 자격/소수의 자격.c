#include <stdio.h>

int    is_prime(int n)
{
    int    i;
    
    i = 2;
    if (n == 1)
        return (0);
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int    is_include(int n, int look)
{
    while (n > 0)
    {
        if (n % 10 == look)
            return (1);
        n /= 10;
    }
    return (0);
}

void    print_cnt(int first, int last, int look)
{
    int    cnt;
    
    cnt = 0;
    while (first <= last)
    {
        if (is_prime(first) && is_include(first, look))
            cnt++;
        first++;
    }
    printf("%d", cnt);
}

int    main(void)
{
    int    a;
    int    b;
    int    d;
    
    scanf("%d %d %d", &a, &b, &d);
    print_cnt(a, b, d);
    return (0);
}