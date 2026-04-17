#include <stdio.h>

int    main(void)
{
    int    i;
    int    l;
    int    p;
    int    v;
    
    i = 0;
    while (1)
    {
        scanf("%d %d %d", &l, &p, &v);
        if (l == 0)
            break; 
        printf("Case %d: %d\n", i + 1, v / p * l + (l < v % p ? l : v % p));
        i++;
    }
}