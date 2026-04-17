#include <stdio.h>
#include <stdlib.h>

int    get_size(int n, int base)
{
    int    size;
    
    size = 0;
    while (n > 0)
    {
        size++;
        n /= base;
    }
    return (size);
}

void    print_base(int n, int base)
{
    int    size;
    int    tmp;
    char    *ans;
 
    size = get_size(n, base);
    ans = malloc(sizeof(char) * (size + 1));
    while (n > 0)
    {
        if (n % base >= 10)
            tmp  = n % base + 55;
        else
            tmp = n % base + '0';
        ans[size - 1] = tmp;
        size--;
        n /= base;
    }
    printf("%s", ans);
}

int    main(void)
{
    int    a;
    int    b;
    
    scanf("%d %d", &a, &b);
    print_base(a, b);
}