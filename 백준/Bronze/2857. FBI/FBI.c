#include <stdio.h>
#include <string.h>

int    main(void)
{
    int    i;
    int    a;
    char    str[11];
    
    a = 0;
    for (i = 0; i < 5; i++)
    {
        scanf("%s", str);
        if (strstr(str, "FBI"))
            a = printf("%d\n", i + 1);
    }
    if (!a)
        printf("HE GOT AWAY!");
}