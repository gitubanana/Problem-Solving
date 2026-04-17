#include <stdio.h>

int    main(void)
{
    int    total_price;
    int    num_of_things;
    int    price;
    int    cnt;
    
    scanf("%d\n%d", &total_price, &num_of_things);
    while (num_of_things--)
    {
        scanf("%d %d", &price, &cnt);
        total_price -= price * cnt;
    }
    printf("%s", total_price == 0 ? "Yes" : "No");
}