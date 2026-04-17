#include <stdio.h>

int    main(void)
{
    int    n;
    int    m;
    int    ans;
    
    scanf("%d %d", &n, &m);
    if (n == m)
        ans = 1;
    else
        ans = 0;
    printf("%d", ans);
}