#include <stdio.h>
#include <stdlib.h>

int    main(void)
{
    int    i;
    int    min;
    int    total;
    int    *arr;
    
    i = 0;
    total = 0;
    arr = (int *)malloc(sizeof(int) * 7);
    while (i < 7)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2)
        {
            if (total == 0)
                min = arr[i];
            total += arr[i];
            min = min > arr[i] ? arr[i] : min;
        }
        i++;
    }
    if (total)
    {
        printf("%d\n", total);
        printf("%d\n", min);
    }
    else
        printf("-1\n");
}