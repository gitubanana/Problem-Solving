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

void    print_decision(char *str)
{
    int    len;
    char    *ans;
    
    len = get_len(str);
    if (str[len / 2] == str[len / 2 - 1])
        ans = "Do-it\n";
    else
        ans = "Do-it-Not\n";
    printf("%s", ans);
}

int    main(void)
{
    int    i;
    int    n;
    char    *str;
    
    i = 0;
    str = malloc(sizeof(char) * 1001);
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", str);
        print_decision(str);
        i++;
    }
    free(str);
}