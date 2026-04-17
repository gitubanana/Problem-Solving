#include <stdio.h>
#include <unistd.h>

void    print_score(int cnt_of_0, int cnt_of_1)
{
    if (cnt_of_0 > cnt_of_1)
    {
        if (cnt_of_0 == 3)
            write(1, "C\n", 2);
        else
            write(1, "D\n", 2);
    }
    else
    {
        if (cnt_of_1 == 3)
            write(1, "A\n", 2);
        else if(cnt_of_1 == 2)
            write(1, "B\n", 2);
        else
            write(1, "E\n", 2);
    }
}

int    main(void)
{
    int    i;
    int    j;
    int    tmp;
    int    cnt_of_0;
    int    cnt_of_1;
    
    i = 0;
    while (i < 3)
    {
        j = 0;
        cnt_of_0 = 0;
        cnt_of_1 = 0;
        while (j < 4)
        {
            scanf("%d", &tmp);
            if (tmp)
                cnt_of_1++;
            else
                cnt_of_0++;
            j++;
        }
        print_score(cnt_of_0, cnt_of_1);
        i++;
    }
}