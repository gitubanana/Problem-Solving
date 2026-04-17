#include <stdio.h>

int    main(void)
{
    int    i;
    int    n;
    int    tmp;
    int    cnt;
    
    i = 0;
    cnt = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d", &tmp);
        if (tmp != i + 1)
            cnt++;
        i++;
    }
    printf("%d", cnt);
}