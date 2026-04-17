#include <stdio.h>
#include <unistd.h>

int    is_prime(int n)
{
    int    i;
    
    i = 2;
    if (n == 1)
        return (0);
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int    main(void)
{
    int    start;
    int    end;
    int    sum;
    int    min;
    
    sum = 0;
    min = 0;
    scanf("%d %d", &start, &end);
    while (start <= end)
    {
        if (is_prime(start))
        {
            if (sum == 0)
                min = start;
            sum += start;   
        }
        start++;
    }
    if (sum)
        printf("%d\n%d", sum, min);
    else
        printf("-1");
}