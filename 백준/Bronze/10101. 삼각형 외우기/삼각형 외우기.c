#include <stdio.h>

int    main(void)
{
    char    *ans;
    int    a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    if (a == 60 && b == 60 && c == 60)
        ans = "Equilateral";
    else if (a + b + c == 180)
    {
        if (a == b || b == c || c == a)
            ans = "Isosceles";
        else
            ans = "Scalene";
    }
    else
        ans = "Error";
    printf("%s", ans);
}