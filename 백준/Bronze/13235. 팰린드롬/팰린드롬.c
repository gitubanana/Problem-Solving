#include <stdio.h>

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

int    is_paelindrome(char *str)
{
    int    i;
    int    len;
    
    i = 0;
    len = get_len(str);
    while (i < len / 2)
    {
        if (str[i] != str[len - 1 - i])
            return (0);
        i++;
    }
    return (1);
}
int    main(void)
{
    char    *ans;
    char    arr[21];
    
    scanf("%s", arr);
    if (is_paelindrome(arr))
        ans = "true";
    else
        ans = "false";
    printf("%s", ans);
}