#include <stdio.h>
#include <stdlib.h>

int    main(void)
{
    int    i;
    int    n;
    char    *str;
    
    i = 0;
    str = malloc(sizeof(char) * 51);
    scanf("%d\n", &n);
    while (i < n)
    {
        gets(str);
        printf("%d. %s\n", i + 1, str);
        i++;
    }
}