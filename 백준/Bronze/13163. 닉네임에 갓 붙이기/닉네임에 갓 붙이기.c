#include <stdio.h>
#include <stdlib.h>

void    print_with_god(char *str)
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    printf("god");
    while (str[i])
    {
        if (str[i] == ' ')
            cnt = 1;
        if (str[i] != ' ' && cnt)
            printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

int    main(void)
{
    int    i;
    int    n;
    char    *str;
    
    i = 0;
    str = malloc(sizeof(char) * 102);
    scanf("%d\n", &n);
    while (i < n)
    {
        gets(str);
        print_with_god(str);
        i++;
    }
    free(str);
}