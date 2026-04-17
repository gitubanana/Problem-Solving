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

char    *base_change(int n, int base)
{
    int    size;
    char    *str;
    
    size = get_size(n, base);
    str = malloc(sizeof(char) * (size + 1));
    while (n > 0)
    {
        if (n % base < 10)
            str[size - 1] = n % base + '0';
        else
            str[size - 1] = n % base + 55;
        size--;
        n /= base;
    }
    return (str);
}

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    is_palindrome(char *str)
{
    int    i;
    int    len;
    
    len = get_len(str);
    for (i = 0; i < len / 2; i++)
        if (str[i] != str[len - 1 - i])
            return (0);
    return (1);
}

int    is_palindrome_base(int n)
{
    int    i;
    
    for (i = 2; i <= 64; i++)
        if (is_palindrome(base_change(n, i)))
            return (1);
    return (0);
}

int    main(void)
{
    int    n;
    int    tmp;
    
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &tmp);
        printf("%d\n", is_palindrome_base(tmp));
    }
}