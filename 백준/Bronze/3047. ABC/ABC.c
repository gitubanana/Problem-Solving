#include <stdio.h>
#include <stdlib.h>

void    bubble_sort(int *arr, int size)
{
    int    i;
    int    j;
    int    tmp;
    
    for(int i = 1, j = 0; i < size; i++)
    {
        tmp = arr[(j = i)];
        while(--j>=0 && tmp<arr[j])
        {
            arr[j+1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void    print_abc(int *arr, int size, char *str)
{
    int    i;
    int    ans;
    
    i = 0;
    bubble_sort(arr, size);
    while (i < 3)
    {
        if (str[i] == 'A')
            ans = arr[0];
        else if (str[i] == 'B')
            ans = arr[1];
        else
            ans = arr[2];
        printf("%d ", ans);
        i++;
    }
}

int    main(void)
{
    int    i;
    int    *arr;
    char    *str;
    
    i = 0;
    arr = malloc(sizeof(int) * 3);
    str = malloc(sizeof(char) * 4);
    scanf("%d %d %d\n", &arr[0], &arr[1], &arr[2]);
    scanf("%s", str);
    print_abc(arr, 3, str);
}