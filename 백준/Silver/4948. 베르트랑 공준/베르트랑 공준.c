#include <stdio.h>

int    is_prime(int n)
{
    int    i;
    
    if (n == 1)
        return (0);
    
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            return (0);
    return (1);
}

void    print_cnt(int start, int end)
{
    int    i, cnt;
    
    cnt = 0;
    for (i = start + 1; i <= end; i++)
        if (is_prime(i))
            cnt++;
    printf("%d\n", cnt);
}

int    main(void)
{
    int    n;
    
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        print_cnt(n, 2 * n);
    }
}