#include <iostream>
#include <algorithm>

int    arr[8];
int    num[8];

void    back_tracking(int cur_v, int &num_cnt, int &comb_cnt, int depth)
{
    int    i;
    
    if (depth == comb_cnt)
    {
        for (i = 0; i < comb_cnt; ++i)
            printf("%d ", num[arr[i]]);
        printf("\n");
        return ;
    }
    for (i = cur_v; i < num_cnt; ++i)
    {
        arr[depth] = i;
        back_tracking(i, num_cnt, comb_cnt, depth + 1);
    }
}

int    main(void)
{
    int    num_cnt, comb_cnt;
    
    scanf(" %d %d", &num_cnt, &comb_cnt);
    for (int i = 0; i < num_cnt; ++i)
        scanf(" %d", &num[i]);
    std::sort(num, num + num_cnt);
    back_tracking(0, num_cnt, comb_cnt, 0);
    return (0);
}