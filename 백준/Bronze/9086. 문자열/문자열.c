#include <stdio.h>
#include <stdlib.h>

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    print_first_last(char *str)
{
    int    len;
    
    len = get_len(str);
    if (len != 1)
        printf("%c%c\n", str[0], str[len - 1]);
    else
        printf("%c%c\n", str[0], str[0]);
}

int    main(void)
{
    int    i;
    int    n;
    char    *str;
    
    i = 0;
    scanf("%d", &n);
    str = malloc(sizeof(char) * 1001);
    while (i < n)
    {
        scanf("%s", str);
        print_first_last(str);
        i++;
    }
    free(str);
}