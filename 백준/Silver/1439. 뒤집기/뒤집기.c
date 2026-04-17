#include <stdio.h>

int    ch_len(char *str, char ch)
{
    int    len;
    
    len = 0;
    while (str[len])
    {
        if (str[len] == ch)
            len++;
        else
            break;
    }
    return (len);
}

int    count_ch(char *str, char ch)
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    while (str[i])
    {
        if (str[i] == ch)
        {
            cnt++;
            i += ch_len(&str[i], ch);
        }
        else
            i++;
    }
    return (cnt);
}

int    main(void)
{
    int    ans;
    char    str[1000001];
    
    scanf("%s", str);
    if (count_ch(str, '0') > count_ch(str, '1'))
        ans = count_ch(str, '1');
    else
        ans = count_ch(str, '0');
    printf("%d", ans);
}