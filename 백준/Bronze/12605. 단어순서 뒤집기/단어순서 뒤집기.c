#include <stdio.h>
#include <string.h>
#define MAX 25

void    print_rev_str(char *str)
{
    int i;

    for (i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[i] = '\0';
            printf("%s ", &str[i + 1]);
        }
    }
    printf("%s", str);
    printf("\n");
}

int    main(void)
{
    int     i, test_cnt;
    char    str[MAX + 1];

    scanf("%d\n", &test_cnt);
    for (i = 1; i <= test_cnt; i++)
    {
        gets(str);
        printf("Case #%d: ", i);
        print_rev_str(str);
    }
    return (0);
}
