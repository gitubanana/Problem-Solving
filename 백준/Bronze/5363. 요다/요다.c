#include <stdio.h>

void    print_yoda(char *str)
{
    int    i;
    int    cnt;
    
    cnt = 0;
    for (i = 0; cnt != 2; i++)
        if (str[i] == ' ')
            cnt++;
    str[i - 1] = 0;
    printf("%s ", &str[i]);
    printf("%s\n", str);
}

int    main(void)
{
    int    n;
    char    str[101];
    
    scanf("%d\n", &n);
    while (n--)
    {
        gets(str);
        print_yoda(str);
    }
}