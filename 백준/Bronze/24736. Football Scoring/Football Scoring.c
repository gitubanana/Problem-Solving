#include <stdio.h>

int    main(void)
{
    int    i;
    int    home[5];
    int    visiting[5];
    
    i = -1;
    while (++i < 5)
        scanf("%d", &visiting[i]);
    i = -1;
    while (++i < 5)
        scanf("%d", &home[i]);
    printf("%d ", visiting[0] * 6 + visiting[1] * 3 + visiting[2] * 2 + visiting[3] * 1+ visiting[4] * 2);
    printf("%d", home[0] * 6 + home[1] * 3 + home[2] * 2 + home[3] * 1+ home[4] * 2);
}