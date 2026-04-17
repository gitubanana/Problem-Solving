#include <stdio.h>

int    main(void)
{
    int    chicken;
    int    coke;
    int    beer;
    int    ans;
    
    scanf("%d %d %d", &chicken, &coke, &beer);
    if (coke / 2 + beer > chicken)
        ans = chicken;
    else
        ans = coke / 2 + beer;
    printf("%d", ans);
}