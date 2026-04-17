#include <stdio.h>
#include <string.h>

int    can_paste(char *str, char *paste)
{
    int    i;
    
    for (i = 0; paste[i]; i++)
        if (str[i] != paste[i])
            return (0);
    return (1);
}

void    print_ans(char *str, char *paste)
{
    int    i;
    int    sec, len;
    
    sec = 0;
    len = strlen(paste);
    for (i = 0; str[i]; i++)
    {
        if (can_paste(&str[i], paste))
            i += len - 1;
        sec++;
    }
    printf("%d\n", sec);
}

int    main(void)
{
    int    n;
    char    str[10001];
    char    paste[101];
    
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s %s", str, paste);
        print_ans(str, paste);
    }
}