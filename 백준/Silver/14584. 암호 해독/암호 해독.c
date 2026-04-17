#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    decrypt(char *str, int back_num)
{
    int    i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] < ('a' + back_num))
            str[i] += (26 - back_num);
        else
            str[i] -= back_num;
        i++;
    }
}

int    is_include(char **words, int size, char *target)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        if (strstr(target, words[i]))
            return (1);
        i++;
    }
    return (0);
}

void    print_decrypted(char *target, char **words, int size)
{
    int    i;
    char    *tmp;
    
    i = 1;
    tmp = malloc(sizeof(char) * 101);
    while (1)
    {
        strcpy(tmp, target);
        decrypt(tmp, i);
        if (is_include(words, size, tmp))
            break;
        i++;
    }
    printf("%s", tmp);
    free(tmp);
}

int    main(void)
{
    int    i;
    int    n;
    char    **words;
    char    *to_decrypt;
    
    i = 0;
    to_decrypt = malloc(sizeof(char) * 101);
    scanf("%s %d", to_decrypt, &n);
    words = malloc(sizeof(char *) * n);
    while (i < n)
    {
        words[i] = malloc(sizeof(char) * 21);
        scanf("%s", words[i]);
        i++;
    }
    print_decrypted(to_decrypt, words, n);
}