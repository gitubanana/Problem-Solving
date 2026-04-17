#include <stdio.h>

int    main(void)
{
    int    i;
    int    n;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        printf("Hello World, Judge %d!\n", i + 1);
        i++;
    }
}