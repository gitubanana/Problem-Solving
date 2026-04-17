#include <stdio.h>
#include <unistd.h>

void    print_plus(int n)
{
    char    ch;
    
    if (n > 0)
        print_plus(n / 10);
    else
        return ;
    ch = n % 10 + '0';
    write(1, &ch ,1);
}
int    main(void)
{
    int    i;
    int    n;
    int    tmp;
    int    max;
    
    i = -1;
    max = 0;
    scanf("%d", &n);
    while (++i < n)
    {
        scanf("%d", &tmp);
        if (max < tmp)
            max = tmp;
    }
    print_plus(max);
}