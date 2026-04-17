#include <stdio.h>

int    main(void)
{
    char    *ans;
    char    str[8];
    
    scanf("%s", str);
    if (str[0] == '5' && str[1] == '5' && str[2] == '5')
        ans = "YES";
    else
        ans = "NO";
    printf("%s", ans);
}