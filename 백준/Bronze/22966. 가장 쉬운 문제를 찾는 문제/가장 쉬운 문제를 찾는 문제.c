#include <stdio.h>
#include <unistd.h>

void    alloc_s(char **arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        arr[i] = malloc(sizeof(char) * 11);
        if (!arr[i])
            return ;
        i++;
    }
}

int    main(void)
{
    int    i;
    int    n;
    int    min;
    int    *iarr;
    char    **arr;
    
    i = 0;
    min = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(char *) * n);
    iarr = malloc(sizeof(int) * n);
    if (!arr || !iarr)
        return (0);
    alloc_s(arr, n);
    while (i < n)
    {
        scanf("%s %d", arr[i], &iarr[i]);
        min = iarr[min] > iarr[i] ? i : min;
        i++;
    }
    printf("%s", arr[min]);
}