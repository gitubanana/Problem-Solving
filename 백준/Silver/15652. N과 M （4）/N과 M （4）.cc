#include <iostream>

int arr[8];

void    back_tracking(int cur_v, int &last_num, int &num_cnt, int depth)
{
    int i;

    if (depth == num_cnt)
    {
        for (i = 0; i < num_cnt; ++i)
            printf("%d ", arr[i]);
        printf("\n");
        return ;
    }
    for (i = cur_v; i <= last_num; ++i)
    {
        arr[depth] = i;
        back_tracking(i, last_num, num_cnt, depth + 1);
    }
}

int main()
{
    int last_num, num_cnt;
    
    scanf(" %d %d", &last_num, &num_cnt);
    back_tracking(1, last_num, num_cnt, 0);
    return 0;
}