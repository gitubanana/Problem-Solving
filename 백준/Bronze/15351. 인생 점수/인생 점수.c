#include <stdio.h>
#include <stdlib.h>

void    print_score(char *str)
{
    int    i;
    int    sum;
    
    i = 0;
    sum = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            sum += str[i] - 64;
        i++;
    }
    if (sum == 100)
        printf("PERFECT LIFE\n");
    else
        printf("%d\n", sum);
}

int    main(void)
{
    int    i;
    int    n;
    char    *str;
    
    i = 0;
    str = malloc(sizeof(char) * 31);
    scanf("%d\n", &n);
    while (i < n)
    {
        gets(str);
        print_score(str);
        i++;
    }
    free(str);
}