#include <stdio.h>
#include <stdlib.h>

int    calculate(int n)
{
    int    ret;
    
    ret = n;
    while (n > 0)
    {
        ret += n % 10;
        n /= 10;
    }
    return (ret);
}

void    print_ans(int n)
{
    int    i;
    int    ans;
    
    i = 1;
    ans = 0;
    while (i < n)
    {
        if (n == calculate(i))
        {
            ans = i;
            break;
        }
        i++;
    }
    printf("%d", ans);
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_ans(n);
}