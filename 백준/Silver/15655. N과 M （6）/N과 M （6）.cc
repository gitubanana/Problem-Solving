#include <iostream>
#include <algorithm>

int         arr[8];
int         num[8];
int         visited[8];

void    back_tracking(int cur_v, int &elem_cnt, int &comb_cnt, int depth)
{
    int i;

    if (depth == comb_cnt)
    {
        for (i = 0; i < comb_cnt; ++i)
            printf("%d ", num[arr[i]]);
        printf("\n");
        return ;
    }
    for (i = 0; i < elem_cnt; ++i)
    {
        if (visited[i] == 0 && (depth == 0 || arr[depth - 1] < i))
        {
            arr[depth] = i;
            visited[i] = 1;
            back_tracking(i, elem_cnt, comb_cnt, depth + 1);
            visited[i] = 0;
        }
    }
}

int main(void)
{
    int elem_cnt, comb_cnt;
    
    scanf(" %d %d", &elem_cnt, &comb_cnt);
    for (int i = 0; i < elem_cnt; ++i)
        scanf(" %d", &num[i]);
    std::sort(num, num + elem_cnt);
    back_tracking(0, elem_cnt, comb_cnt, 0);
    return (0);
}
