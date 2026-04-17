#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int    s; //sourness
    int    b; //bitterness
}ing; //ingredient

int    min = 1000000001, size;

void    scan_ing(ing *arr)
{
    int    i;
    
    i = -1;
    while (++i < size)
        scanf("%d %d", &arr[i].s, &arr[i].b);
}

void    find_min(ing *arr, int n, int depth, int s, int b)
{
    int    i, gap;
    
    if (depth == n)
    {
        if (min > (gap = abs(s - b)))
            min = gap;
        return ;
    }
    
    for (i = depth + 1; i < size; i++)
        find_min(arr, n, i, s * arr[i].s, b + arr[i].b);
}

int    main(void)
{
    int    i, j;
    ing    *arr;
    
    scanf("%d", &size);
    arr = malloc(sizeof(ing) * size);
    scan_ing(arr);
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            find_min(arr, i, j, arr[j].s, arr[j].b);
    printf("%d", min);
}