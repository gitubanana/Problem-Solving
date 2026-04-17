#include <stdio.h>
#include <stdlib.h>

int    main(void)
{
    int    i;
    int    n;
    char    str[30];
    
    i = -1;
    scanf("%d\n", &n);
    while (++i < n)
    {
        gets(str);
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        printf("%s\n", str);
    }
}