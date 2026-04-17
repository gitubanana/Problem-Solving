#include <stdio.h>

int    main(void)
{
    int    i;
    int    cnt;
    char    tmp;
    
    cnt = 0;
    for (i = 0; i < 6; i++)
    {
        tmp = getchar();
        getchar();
        if (tmp == 'W')
            cnt++;
    }
    if (cnt >= 5)
        i = 1;
    else if (cnt >= 3)
        i = 2;
    else if (cnt >= 1)
        i = 3;
    else
        i = -1;
    printf("%d", i);
}