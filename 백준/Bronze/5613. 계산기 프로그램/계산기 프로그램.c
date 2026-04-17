#include <stdio.h>

int    calculate(int a, char oper, int b);

int    main(void)
{
    int    a;
    int    b;
    int    result;
    char   oper;
    
    scanf("%d %c %d", &a, &oper, &b);
    result = calculate(a, oper, b);
    while (1)
    {
        scanf(" %c", &oper);
        if (oper == '=')
            break;
        scanf(" %d", &a);
        result = calculate(result, oper, a);
    }
    printf("%d", result);
    return (0);
}

int    calculate(int a, char oper, int b)
{
    if (oper == '+')
        return (a + b);
    if (oper == '-')
        return (a - b);
    if (oper == '*')
        return (a * b);
    if (oper == '/')
        return (a / b);
}