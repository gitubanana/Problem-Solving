#include <stdio.h>

int    main(void)
{
    int    i;
    char    *ans;
    int    num[4];
    
    i = 0;
    while (i < 4)
        scanf("%d", &num[i++]);
    if ((num[0] == 9 || num[0] == 8) && (num[1] == num[2]) && (num[3] == 9 || num[3] == 8))
                ans = "ignore";
    else
        ans = "answer";
    printf("%s", ans);
}