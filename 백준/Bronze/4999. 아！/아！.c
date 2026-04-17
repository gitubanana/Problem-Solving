#include <stdio.h>

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    main(void)
{
    char    *ans;
    char    s1[1001];
    char    s2[1001];
    
    scanf("%s %s", s1, s2);
    if (get_len(s1) >= get_len(s2))
        ans = "go";
    else
        ans = "no";
    printf("%s", ans);
}