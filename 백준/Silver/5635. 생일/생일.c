#include <stdio.h>
#include <stdlib.h>

typedef struct birth
{
    char    str[16];
    int    y;
    int    m;
    int    d;
}birth;

void    print_max_min(birth *arr, int size)
{
    int    i;
    birth   max;
    birth   min;
    
    i = 0;
    max = arr[0];
    min = arr[0];
    while (i < size)
    {
        if (arr[i].y < max.y)
            max = arr[i];
        else if (arr[i].y == max.y)
        {
            if (arr[i].m < max.m)
                max = arr[i];
            else if (arr[i].m == max.m)
                if (arr[i].d < max.d)
                    max = arr[i];
        }
        if (arr[i].y > min.y)
            min = arr[i];
        else if (arr[i].y == min.y)
        {
            if (arr[i].m > min.m)
                min = arr[i];
            else if (arr[i].m == min.m)
                if (arr[i].d > min.d)
                    min = arr[i];
        }
        i++;
    }
    printf("%s\n%s", min.str, max.str);
}

int    main(void)
{
    int    i;
    int    n;
    birth    *arr;
    
    i = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(birth) * n);
    
    while (i < n)
    {
        scanf("%s %d %d %d", arr[i].str, &arr[i].d, &arr[i].m, &arr[i].y);
        i++;
    }
    print_max_min(arr, n);
    free(arr);
}