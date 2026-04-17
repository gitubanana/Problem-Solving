#include <stdio.h>

int    main(void)
{
    int    i;
    char    str[101];
    
    i = -1;
    scanf("%s", str);
    while (str[++i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i] + 32);
    }
}