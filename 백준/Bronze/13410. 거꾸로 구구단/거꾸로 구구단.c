#include <stdio.h>

int    get_n(int n)
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

void    print_ans(int dan, int num)
{
    int    i;
    int    tmp;
    int    max;
    
    i = 0;
    max = 0;
    while (i < num)
    {
        tmp = get_n(dan * (i + 1));
        if (max < tmp)
            max = tmp;
        i++;
    }
    printf("%d", max);
}

int    main(void)
{
    int    dan;
    int    num;
    
    scanf("%d %d", &dan, &num);
    print_ans(dan, num);
}