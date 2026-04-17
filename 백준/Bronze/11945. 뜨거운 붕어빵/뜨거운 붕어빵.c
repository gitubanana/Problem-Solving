#include <stdio.h>
#include <stdlib.h>

int    get_len(char *arr)
{
    int    len;
    
    len = 0;
    while (arr[len])
        len++;
    return (len);
}

void    rev_print(char *arr)
{
    int    len;
    
    len = get_len(arr);
    while (len--)
        printf("%c", arr[len]);
    printf("\n");
}

int    main(void)
{
    int    i;
    int    n;
    int    m;
    char    *arr;
    
    i = 0;
    scanf("%d %d", &n, &m);
    arr = malloc(sizeof(char) * (m + 1));
    while (i < n)
    {
        scanf("%s", arr);
        rev_print(arr);
        i++;
    }
}