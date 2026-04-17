#include <stdio.h>
#include <stdlib.h>

void    init(int *arr, int size)
{
    int    i;
    
    i = -1;
    while (++i < size)
        arr[i] = i + 1;
}

void    ft_rev(int *arr, int start, int end)
{
    int    i;
    int    tmp;
    int    size;
    
    i = 0;
    size = end - start;
    end--;
    start--;
    while (i <= size / 2)
    {
      tmp = arr[start + i];
      arr[start + i] = arr[end - i];
      arr[end - i] = tmp;
      i++;
    }
}

int    main(void)
{
    int    i;
    int    start;
    int    end;
    int    *arr;
    
    i = 0;
    arr = malloc(sizeof(int) * 20);
    init(arr, 20);
    while (i < 10)
    {
        scanf("%d %d", &start, &end);
        ft_rev(arr, start, end);
        i++;
    }
    i = 0;
    while (i < 20)
        printf("%d ", arr[i++]);
    free(arr);
}