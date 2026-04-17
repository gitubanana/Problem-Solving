#include <stdio.h>
#include <stdlib.h>

void    print_name_score(char *str)
{
    int    i;
    int    sum;
    
    i = 0;
    sum = 0;
    while (str[i])
    {
        sum += str[i] - 64;
        i++;
    }
    printf("%d", sum);
}

int    main(void)
{
    int    n;
    int    sum;
    char    *str;
    
    sum = 0;
    scanf("%d", &n);
    str = malloc(sizeof(char) * (n + 1));
    scanf("%s", str);
    print_name_score(str);
    free(str);
}