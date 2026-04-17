#include <stdio.h>
#include <string.h>

void    print_ans(char *str, char *key)
{
    int    i, j;
    int    flag;
    
    flag = j = 0;
    if (strstr(str, key))
    {
        printf("1");
        return ;
    }
    for (i = 0; str[i]; i++)
    {
        if (str[i] == key[j])
            flag = 1;
        
        if (str[i] == key[j] && key[j] && flag)
            j++;
        else if ((str[i] < '0' || str[i] > '9') && flag)
            flag = j = 0;
    }
    printf("%d", key[j] == '\0' ? 1 : 0);
}

int    main(void)
{
    char    str[101];
    char    key[101];
    
    scanf("%s %s", str, key);
    print_ans(str, key);
}