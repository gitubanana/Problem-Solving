#include <stdio.h>
#include <stdlib.h>

int    cal_base(char *str, int base)
{
    int         i;
    int         j;
    int         sum;
    const char  arr[] = "0123456789abcdef";
    
    i = 0;
    j = 0;
    sum = 0;
    while (str[i])
    {
        j = 0;
        while (j < base)
        {
            if (str[i] == arr[j])
            {
                sum = sum * base + j;
                break;
            }
            j++;
        }
        i++;
    }
    return (sum);
}

int    main(void)
{
    int         base;
    char        *str;
    
    str = malloc(sizeof(char) * 11);
    scanf("%s", str);
    if (str[0] == '0')
    {
        if (str[1] == 'x')
            base = 16;
        else
            base = 8;
    }
    else
        base = 10;
    printf("%d", cal_base(str, base));
}