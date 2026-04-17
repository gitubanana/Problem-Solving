#include <stdio.h>

int    fibonacci(int n)
{
    int    i;
    int    one;
    int    two;
    int    tmp;
    
    i = 0;
    one = 0;
    two = 1;
    if (n == 0 || n == 1)
        return (n);
    while (i < n - 1)
    {
        tmp = two;
        two += one;
        one = tmp;
        i++;
    }
    return (two);
}

int    main(void)
{
    int    n;
    
    scanf("%d", &n);
    printf("%d", fibonacci(n));
    return (0);
}