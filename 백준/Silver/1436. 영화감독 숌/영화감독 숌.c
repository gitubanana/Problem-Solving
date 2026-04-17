#include <stdio.h>

int    is_include(int n)
{
    while (n > 0)
    {
        if (n % 10 == 6 && n / 10 % 10 == 6 && n / 100 % 10 == 6)
            return (1);
        n /= 10;
    }
    return (0);
}

void    print_title(int n)
{
    int    i;
    int    cnt;
    
    i = 665;
    cnt = 0;
    while (1)
    {
        if (is_include(i))
            cnt++;
        if (cnt == n)
            break;
        i++;
    }
    printf("%d", i);
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_title(n);
}