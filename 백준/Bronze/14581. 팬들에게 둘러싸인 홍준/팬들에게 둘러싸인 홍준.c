#include <stdio.h>

void    print_ans(char str[])
{
    printf(":fan::fan::fan:\n");
    printf(":fan:");
    printf(":%s:", str);
    printf(":fan:\n");
    printf(":fan::fan::fan:\n");
}

int    main(void)
{
    char    str[21];
    
    scanf("%s", str);
    print_ans(str);
}