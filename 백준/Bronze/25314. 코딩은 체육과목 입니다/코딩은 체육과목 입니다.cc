#include <iostream>

int    main(void)
{
    int    byte;
    int    long_cnt;
    
    scanf(" %d", &byte);
    long_cnt = byte / 4;
    for (int i = 0; i < long_cnt; i++)
        printf("long ");
    printf("int\n");
    return (0);
}