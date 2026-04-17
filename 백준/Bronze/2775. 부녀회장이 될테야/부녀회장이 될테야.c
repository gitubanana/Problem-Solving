#include <stdio.h>

int    get_living_num(int floor, int room_num)
{
    int    i;
    int    sum;
    
    i = 1;
    sum = 0;
    if (floor == 0)
        return (room_num);
    while (i <= room_num)
    {
        sum += get_living_num(floor - 1, i);
        i++;
    }
    return (sum);
}

int    main(void)
{
    int    i;
    int    t;
    int    floor;
    int    room_num;
    
    i = -1;
    scanf("%d", &t);
    while (++i < t)
    {
        scanf("%d %d", &floor, &room_num);
        printf("%d\n", get_living_num(floor, room_num));
    }
    return (0);
}