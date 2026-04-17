#include <iostream>

int    get_divisor(int num, int aim)
{
    int    divisor, limit;
    
    limit = num / 2;
    for (divisor = 1; divisor <= limit; ++divisor)
    {
        aim -= (num % divisor == 0);
        if (aim == 0)
            return (divisor);
    }
    return ((aim == 1) * num);
}

int    main(void)
{
    int    num, aim;
    
    scanf(" %d %d", &num, &aim);
    printf("%d\n", get_divisor(num, aim));
    return (0);
}