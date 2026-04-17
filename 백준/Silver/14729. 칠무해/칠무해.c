#include <stdio.h>
#include <stdlib.h>

double arr[10000000];

void    print_ans(int size)
{
    int    i, j;
    int    tmp;
    double    min;
    
    i = 0;
    while (i < 7)
    {
        j = 0;
        min = 101.0;
        while (j < size)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                tmp = j;
            }
            j++;
        }
        arr[tmp] = 101.0;
        printf("%.3lf\n", min);
        i++;
    }
}

int    main(void)
{
    int    i;
    int    n;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
        scanf("%lf", &arr[i++]);
    print_ans(n);
}