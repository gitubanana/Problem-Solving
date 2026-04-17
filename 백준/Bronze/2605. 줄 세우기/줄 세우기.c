#include <stdio.h>
#include <stdlib.h>

void    init_1_to_n(int *arr, int n)
{
    int    i;
    
    i = 0;
    while (i < n)
    {
        arr[i] = i + 1;
        i++;
    }
}

void    make_line(int *go, int *line, int size)
{
    int    i;
    int    j;
    int    tmp;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        tmp = line[i];
        while (j < go[i])
        {
            line[i - j] = line[i - j - 1];
            j++;
        }
        line[i - go[i]] = tmp;
        i++;
    }
}

void    print_arr(int *arr, int size)
{
    int    i;
    
    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
}

int    main(void)
{
    int    i;
    int    n;
    int    *go;
    int    *line;
    
    i = 0;
    scanf("%d", &n);
    go = malloc(sizeof(int) * n);
    line = malloc(sizeof(int) * n);
    while (i < n)
        scanf("%d", &go[i++]);
    init_1_to_n(line, n);
    make_line(go, line, n);
    print_arr(line, n);
    free(go);
    free(line);
}