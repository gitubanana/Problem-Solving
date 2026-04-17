#include <stdio.h>
#include <stdlib.h>

int    get_size(int n)
{
    int    size;
    
    size = 0;
    while (n > 0)
    {
        n /= 2;
        size++;
    }
    return size;
}

char    *change_base(int n)
{
    int    size;
    char    *arr;
    
    size = get_size(n);
    arr = malloc(sizeof(char) * (size + 1));
    while (n > 0)
    {
        arr[size - 1] = n % 2 + '0';
        size--;
        n /= 2;
    }
    return (arr);
}

void    print_ans(int aim)
{
    int    i, ans;
    char    *str;
    
    ans = 0;
    str = change_base(aim);
    for (i = 0; str[i]; i++)
        if (str[i] == '1')
            ans++;
    printf("%d", ans);
}

int    main(void)
{
    int    x;
    
    scanf("%d", &x);
    print_ans(x);
}