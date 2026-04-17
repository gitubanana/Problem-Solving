#include <unistd.h>
#include <stdio.h>

int    main(void)
{
    int    i;
    int    tmp;
    int    total[2] = {0, };
    
    i = 0;
    while (i < 2)
    {
        scanf("%d", &tmp);
        total[i] += tmp * 3;
        scanf("%d", &tmp);
        total[i] += tmp * 2;
        scanf("%d", &tmp);
        total[i] += tmp * 1;
        i++;
    }
    if (total[0] > total[1])
        write(1, "A", 1);
    else if (total[0] < total[1])
        write(1, "B", 1);
    else
        write(1, "T", 1);
}