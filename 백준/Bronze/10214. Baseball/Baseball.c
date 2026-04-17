#include <stdio.h>

int    main(void)
{
    int    i;
    int    j;
    int    n;
    int    y;
    int    k;
    int    arr[2];
    char    *ans;
    
    i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        j = 0;
        y = 0;
        k = 0;
        while (j < 9)
        {
            scanf("%d %d", &arr[0], &arr[1]);
            y += arr[0];
            k += arr[1];
            j++;
        }
        if (y > k)
            ans = "Yonsei";
        else if (y < k)
            ans = "Korea";
        else
            ans = "Draw";
        printf("%s\n", ans);
        i++;
    }
}