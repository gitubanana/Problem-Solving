#include <stdio.h>
#include <stdlib.h>

void    print_frequency(char *str, char target)
{
    int    i;
    int    frequency;
    
    i = 0;
    frequency = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            if (str[i] == target || str[i] - 32 == target || str[i] + 32 == target)
                frequency++;
        i++;
    }
    printf("%c %d\n", target, frequency);
}

int    main(void)
{
    char    target;
    char    *str;
    
    str = malloc(sizeof(char) * 251);
    while (1)
    {
        scanf("%c ", &target);
        if (target == '#')
            break;
        gets(str);
        print_frequency(str, target);
    }
    free(str);
}