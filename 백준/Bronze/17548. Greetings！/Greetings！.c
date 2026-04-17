#include <stdio.h>

int    get_cnt(char *str)
{
    int    i;
    int    cnt;
    
    cnt = 0;
    for (i = 1; str[i]; i++)
        if (str[i] == 'e')
            cnt++;
    return (cnt);
}

void    print_e(char *str)
{
    int    i;
    int    cnt = get_cnt(str);
    
    for (i = 0; i < cnt * 2; i++)
        printf("e");
}

int    main(void)
{
    char    str[1001];
    
    scanf("%s", str);
    printf("h");
    print_e(str);
    printf("y");
}