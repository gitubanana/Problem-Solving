#include <stdio.h>

int    rev(int n)
{
    int    ret;
    
    ret = 0;
    while (n > 0)
    {
        ret = ret * 10 + (n % 10);
        n /= 10;
    }
    return (ret);
}

void    print_ans(int a, int b)
{
    int    sum;
    
    sum = rev(rev(a) + rev(b));
    printf("%d", sum);
}

int    main(void)
{
    int    a;
    int    b;
    
    scanf("%d %d", &a, &b);
    print_ans(a, b);
}