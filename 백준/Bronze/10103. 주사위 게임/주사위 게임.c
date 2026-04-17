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
    write(1, &ch, 1);
}

int    main(void)
{
    int    i;
    int    n;
    int    a;
    int    b;
    int    c;
    int    d;
    
    i = 0;
    a = 100;
    b = 100;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d %d", &c, &d);
        if (c > d)
            b -= c;
        else if (c < d)
            a -= d;
        i++;
    }
    print_plus(a);
    write(1, " ", 1);
    print_plus(b);
}