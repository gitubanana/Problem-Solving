#include <stdio.h>

void    print_ans(int n)
{
    int    i;
    int    tmp;
    
    if (n == 1)
        return ;
    
    while (n != 1)
    {
        for (i = 2; i < n; i++)
            if (n % i == 0)
                break;
        printf("%d\n", i);
        n /= i;
    }
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_ans(n);
}