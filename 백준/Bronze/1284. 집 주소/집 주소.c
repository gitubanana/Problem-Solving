#include <stdio.h>
#include <stdlib.h>

int    get_cm(char *str)
{
    int    i;
    int    cm;
    
    i = -1;
    cm = 0;
    while (str[++i])
    {
        if (str[i] == '0')
            cm += 4;
        else if (str[i] == '1')
            cm += 2;
        else
            cm += 3;
        if (str[i + 1] != '\0')
            cm++;
    }
    return (cm);
}

int    main(void)
{
    int    cm;
    char    *str;
    
    str = calloc(sizeof(char), 5);
    while (1)
    {
        cm = 0;
        scanf("%s", str);
        if (str[0] == '0')
            break;
        cm += get_cm(str) + 2;
        printf("%d\n", cm);
    }
}