#include <stdio.h>
#include <stdlib.h>

void    print_normal(char **arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        printf("%s\n", arr[i]);
        i++;
    }
}

void    print_ltor(char **arr, int size)
{
    int    i;
    int    j;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            printf("%c", arr[i][size - 1 - j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

void    print_utod(char **arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        printf("%s\n", arr[size - 1 - i]);
        i++;
    }
}

void    print_ans(char **arr, int size, int mind)
{
    if (mind == 1)
        print_normal(arr, size);
    else if (mind == 2)
        print_ltor(arr, size);
    else
        print_utod(arr, size);
}

int    main(void)
{
    int    i;
    int    n;
    int    mind;
    char    **arr;
    
    i = 0;
    scanf("%d", &n);
    arr = malloc(sizeof(char *) * n);
    while (i < n)
    {
        arr[i] = malloc(sizeof(char) * (n + 1));
        scanf("%s", arr[i++]);
    }
    scanf("%d", &mind);
    print_ans(arr, n, mind);
}