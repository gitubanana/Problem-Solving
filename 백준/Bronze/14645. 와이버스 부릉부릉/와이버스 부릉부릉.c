#include <stdio.h>

int    main(void)
{
    int    i;
    int    n;
    int    tmp;
    int    temp;
    
    i = 0;
    scanf("%d %d", &n, &tmp);
    while (i < n)
    {
        scanf("%d %d", &tmp, &temp);
        i++;
    }
    printf("비와이");
}