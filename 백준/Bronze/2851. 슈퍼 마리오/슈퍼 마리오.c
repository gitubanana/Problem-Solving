#include <stdio.h>
#include <stdlib.h>

void    print_ans(int *arr, int size, int aim)
{
    int    i;
    int    sum;
    
    i = 0;
    sum = 0;
    while (i < size)
    {
        if (abs(sum - aim) >= abs(sum + arr[i] - aim))
            sum += arr[i];
        else
            break;
        i++;
    }
    printf("%d", sum);
}

int    main(void)
{
    int    i;
    int    arr[10];
    
    i = 0;
    while (i < 10)
        scanf("%d", &arr[i++]);
    print_ans(arr, 10, 100);
}