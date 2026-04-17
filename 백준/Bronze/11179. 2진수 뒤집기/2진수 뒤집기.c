#include <stdio.h>
#include <stdlib.h>

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

char    *itoa(int n, int size)
{
    char    *str;
    
    str = malloc(size + 1);
    while (n > 0)
    {
        size--;
        str[size] = n % 2 + '0';
        n /= 2;
    }
    return (str);
}

void    rev(char *str, int len)
{
    int    i;
    char    tmp;
    
    for (i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
}

int    atoi_base(char *str, int len)
{
    int    i, n;
    
    n = 0;
    for (i = 0; i < len; i++)
        n  = n * 2 + (str[i] - '0');
    return n;
}

void    print_ans(int n)
{
    int    size;
    char    *str;
    
    size = get_size(n);
    str = itoa(n, size);
    rev(str, size);
    printf("%d", atoi_base(str, size));
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    print_ans(n);
}