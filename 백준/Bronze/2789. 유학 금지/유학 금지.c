#include <stdio.h>
#include <stdlib.h>

int    is_include(char *str, char ch)
{
    int    i;
    
    i = -1;
    while (str[++i])
        if (str[i] == ch)
            return (1);
    return (0);
}

void    print_without(char *check, char *str)
{
    int    i;
    
    i = 0;
    while (str[i])
    {
        if (!is_include(check, str[i]))
            printf("%c", str[i]);
        i++;
    }
}

int    main(void)
{
    char    *str;
    
    str = malloc(sizeof(char) * 101);
    scanf("%s", str);
    print_without("CAMBRIDGE", str);
    free(str);
}