#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    is_palindrome(char *arr)
{
    int    i;
    int    len;
    
    i = 0;
    len = get_len(arr);
    while (i < len / 2)
    {
        if (arr[i] != arr[len - 1 - i])
            return (0);
        i++;
    }
    return (1);
}

int    main(void)
{
    char    *arr;
    
    arr = (char *)malloc(sizeof(char) * 6);
    while (1)
    {
        scanf("%s", arr);
        if (arr[0] == '0')
            break;
        if (is_palindrome(arr))
            write(1, "yes\n", 4);
        else
            write(1, "no\n", 3);
    }
    return (0);
}