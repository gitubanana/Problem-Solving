#include <stdio.h>

int    main(void)
{
    int a, b, xor_cnt;

    scanf("%d %d %d", &a, &b, &xor_cnt);
    printf("%d", xor_cnt % 2 == 0 ? a : a^b);
    return (0);
}