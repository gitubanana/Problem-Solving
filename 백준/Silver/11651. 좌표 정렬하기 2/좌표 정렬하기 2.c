#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int    x;
    int    y;
}pnt; //point

int    cmp(const void *a, const void *b)
{
    pnt    c, d;
    
    c = *(pnt *)a;
    d = *(pnt *)b;
    if (c.y >= d.y)
    {
        if (c.y == d.y)
        {
            if (c.x > d.x)
                return (1);
            return (0);
        }
        return (1);
    }
    return (0);
}

void    print_ans(pnt *arr, int size)
{
    int    i;
    
    qsort(arr, size, sizeof(pnt), cmp);
    for (i = 0; i < size; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);
}

int    main(void)
{
    int    i, n;
    pnt    *arr;
    
    scanf("%d", &n);
    arr = malloc(sizeof(pnt) * n);
    for (i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    print_ans(arr, n);
    free(arr);
}