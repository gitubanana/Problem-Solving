#include <stdio.h>

int    main(void)
{
    int    antenna;
    int    eye;
    
    scanf("%d %d", &antenna, &eye);
    if (antenna >= 3 && eye <= 4)
        printf("TroyMartian\n");
    if (antenna <= 6 && eye >= 2)
        printf("VladSaturnian\n");
    if (antenna <= 2 && eye <= 3)
        printf("GraemeMercurian\n");
}