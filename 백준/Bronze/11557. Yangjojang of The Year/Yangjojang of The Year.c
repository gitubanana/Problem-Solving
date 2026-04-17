#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int    d; //drink
    char    n[21]; //name
}sch; //school

int    main(void)
{
    int    i;
    int    j;
    int    n;
    int    m;
    sch    tmp;
    sch    max;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        j = 0;
        max.d = 0;
        scanf("%d", &m);
        while (j < m)
        {
            scanf("%s %d", &tmp.n, &tmp.d);
            if (tmp.d > max.d)
                max = tmp;
            j++;
        }
        printf("%s\n", max.n);
        i++;
    }
}