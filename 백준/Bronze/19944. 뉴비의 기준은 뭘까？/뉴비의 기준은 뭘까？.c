#include <stdio.h>

int    main(void)
{
    int    n;
    int    m;
    char    *ans;
    
    scanf("%d %d", &n, &m);
    if (m == 1 || m == 2)
        ans = "NEWBIE!";
    else if (m <= n)
        ans = "OLDBIE!";
    else
        ans = "TLE!";
    printf("%s", ans);
}