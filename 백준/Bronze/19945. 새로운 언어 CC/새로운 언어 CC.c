#include <stdio.h>

int    get_size(int n)
{
    int    size;
    
    size = 0;
    while (n > 0)
    {
        size++;
        n /= 2;
    }
    return (size);
}

void    print_ans(int n)
{
    int    ans;
    
    if (n == 0)
        ans = 1;
    else if (n < 0)
        ans = 32;
    else
        ans = get_size(n);
    printf("%d", ans);
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_ans(n);
}