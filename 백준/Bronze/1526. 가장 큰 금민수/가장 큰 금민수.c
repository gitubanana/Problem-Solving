#include <stdio.h>

int    is_gold_num(int n)
{
    while (n > 0)
    {
        if (n % 10 != 7 && n % 10 != 4)
            return (0);
        n /= 10;
    }
    return (1);
}

void    print_ans(int n)
{
    while (n)
    {
        if (is_gold_num(n))
        {
            printf("%d", n);
            break;
        }
        n--;
    }
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_ans(n);
}