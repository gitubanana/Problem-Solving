#include <iostream>

int    main(void)
{
    int    multi_cnt, total;
    
    total = 0;
    scanf(" %d", &multi_cnt);
    for (int i = 0, tmp; i < multi_cnt; ++i)
    {
        scanf(" %d", &tmp);
        total += tmp;
    }
    printf("%d\n", total - multi_cnt + 1);
    return (0);
}