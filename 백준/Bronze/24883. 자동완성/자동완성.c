#include <stdio.h>

int    main(void)
{
    char    ch;
    char    *ans;
    
    scanf("%c", &ch);
    if (ch == 'n' || ch == 'N')
        ans = "Naver D2";
    else
        ans = "Naver Whale";
    printf("%s", ans);
}