#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    decrypt_caesar(char *str)
{
    int    i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'D' && str[i] <= 'Z')
            str[i] -= 3;
        else
            str[i] += 23;
        i++;
    }
}

void    putstr(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    write(1, str, len);
}

int    main(void)
{
    char    *str;
    
    str = malloc(sizeof(char) * 1001);
    scanf("%s", str);
    decrypt_caesar(str);
    putstr(str);
}