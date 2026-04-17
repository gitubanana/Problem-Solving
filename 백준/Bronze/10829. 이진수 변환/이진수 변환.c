#include <stdio.h>

void    print_bin(long long n)
{
    if (n > 0)
        print_bin(n / 2);
    else
        return ;
    printf("%lld", n % 2);
}

int    main(void)
{
    long long    n;
    
    scanf("%lld", &n);
    print_bin(n);
}