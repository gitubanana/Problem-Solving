#include <stdio.h>

void    print(int num, int base)
{
    const char arr[] = "0123456789ABCDEF";
    if (num > 0)
        print(num / base, base);
    else
        return ;
    printf("%c", arr[num % base]);
}

int    main(void)
{
    int    m;
    int    n;
    
    scanf("%d %d", &m, &n);
    if (m == 0)
    {
        printf("0");
        return (0);
    }
    print(m, n);
    return (0);
}