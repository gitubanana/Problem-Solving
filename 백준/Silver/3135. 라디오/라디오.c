#include <stdio.h>
#include <stdlib.h>

void    print_min(int current, int want_to_go, int min)
{
    int    ans;
    
    if (min < abs(current - want_to_go))
        ans = min + 1;
    else
        ans = abs(current - want_to_go);
    printf("%d", ans);
}

int    main(void)
{
    int    i;
    int    n;
    int    min;
    int    tmp;
    int    current;
    int    want_to_go;
    
    i = 0;
    scanf("%d %d %d", &current, &want_to_go, &n);
    while (i < n)
    {
        scanf("%d", &tmp);
        if (i == 0)
            min = abs(tmp - want_to_go);
        if (min > abs(tmp - want_to_go))
            min = abs(tmp - want_to_go);
        i++;
    }
    print_min(current, want_to_go, min);
}