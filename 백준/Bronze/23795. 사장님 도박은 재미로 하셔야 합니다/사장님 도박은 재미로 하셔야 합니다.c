#include <stdio.h>

int    main(void)
{
    int    tmp;
    int    total;
    
    total = 0;
    while (1)
    {
        scanf("%d", &tmp);
        if (tmp == -1)
            break;
        total += tmp;
    }
    printf("%d", total);
}