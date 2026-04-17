#include <stdio.h>

int    main(void)
{
    int    m;
    int    d;
    char    *ans;
    
    scanf("%d %d", &m, &d);
    if (m > 2)
        ans = "After";
    else if (m == 2)
    {
        if (d == 18)
            ans = "Special";
        else if (d > 18)
            ans = "After";
        else
            ans = "Before";
    }
    else
        ans = "Before";
    printf("%s", ans);
}