#include <stdio.h>

int    is_small(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return (1);
    return (0);
}

int    is_capital(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return (1);
    return (0);
}

void    rot_13(char *str)
{
    int    i;
    
    i = -1;
    while (str[++i])
    {
        if (is_small(str[i]))
        {
            if (str[i] >= 'a' && str[i] <= 'm')
                str[i] += 13;
            else
                str[i] -= 13;
        }
        else if (is_capital(str[i]))
        {
            if (str[i] >= 'A' && str[i] <= 'M')
                str[i] += 13;
            else
                str[i] -= 13;
        }
    }
}

int    main(void)
{
    char    str[101];
    
    gets(str);
    rot_13(str);
    printf("%s", str);
    return (0);
}