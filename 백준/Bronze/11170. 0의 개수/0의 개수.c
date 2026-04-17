#include <stdio.h>

int    count_zero(int n)
{
    int    cnt;
    
    cnt = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        if (n % 10 == 0)
            cnt++;
        n /= 10;
    }
    return (cnt);
}

void    print_ans(int start, int end)
{
    int    cnt;
    
    cnt = 0;
    while (start <= end)
    {
        cnt += count_zero(start);
        start++;
    }
    printf("%d\n", cnt);
}

int    main(void)
{
    int    n;
    int    start;
    int    end;
    
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &start, &end);
        print_ans(start, end);
    }
}