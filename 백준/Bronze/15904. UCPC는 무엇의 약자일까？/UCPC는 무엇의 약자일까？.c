#include <stdio.h>
#include <stdlib.h>

void    print_UCPC(char *str)
{
    int    i;
    int    idx;
    char    *ans;
    char    *words = "UCPC";
    
    i = 0;
    idx = 0;
    while (str[i])
    {
        if (str[i] == words[idx] && idx != 4)
            idx++;
        i++;
    }
    if (idx == 4)
        ans = "I love UCPC";
    else
        ans = "I hate UCPC";
    printf("%s", ans);
}

int    main(void)
{
    char    *str;
    
    str = malloc(sizeof(char) * 1001);
    scanf("%[^\n]", str);
    print_UCPC(str);
    free(str);
}