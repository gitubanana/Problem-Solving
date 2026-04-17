#include <stdio.h>

void    print_ans(int *arr, int size, int aim)
{
    int    i;
    int    cnt;
    
    i = 0;
    cnt = 0;
    while (i < size)
    {
        if (arr[i] == aim)
            cnt++;
        i++;
    }
    printf("%d", cnt);
}

int    main(void)
{
    int    i;
    int    tea;
    int    arr[5];
    
    i = 0;
    scanf("%d", &tea);
    while(i < 5)
        scanf("%d", &arr[i++]);
    print_ans(arr, 5, tea);
}