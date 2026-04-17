#include <stdio.h>
#include <stdlib.h>

int    get_len(char *str)
{
    int    len;
    
    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    ft_rev(char *str)
{
    int    i;
    int    len;
    int    tmp;
    
    i = 0;
    len = get_len(str);
    while (i < len / 2)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
        i++;
    }
}

int    my_atoi(char *str)
{
    int    i;
    int    n;
    
    i = 0;
    n = 0;
    while (str[i])
    {
        n = n * 10 + (str[i] - '0');
        i++;
    }
    return (n);
}

int    get_size(int n)
{
    int    size;
    
    size = 0;
    while (n > 0)
    {
        size++;
        n /= 10;
    }
    return (size);
}

char    *my_itoa(int num)
{
    int    i;
    int    size;
    char    *ret;
    
    i = 0;
    size = get_size(num);
    ret = malloc(sizeof(char) * (size + 1));
    while (i < size)
    {
        ret[size - 1 - i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    return (ret);
}

int    is_palindrome(char *str)
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

void    print_ans(char *str)
{
    int    sum;
    char    *ans;
    char    ori[7];
    
    strcpy(ori, str);
    ft_rev(str);
    sum  = my_atoi(str) + my_atoi(ori);
    if (is_palindrome(my_itoa(sum)))
        ans = "YES";
    else
        ans = "NO";
    printf("%s\n", ans);
}

int    main(void)
{
    int    i;
    int    n;
    char    str[7];
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%s", str);
        print_ans(str);
        i++;
    }
}