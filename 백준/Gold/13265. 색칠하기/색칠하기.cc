#include <cstring>
#include <iostream>

enum e_color
{
    NONE,
    BLACK,
    WHITE
};

const int   MAX = 1001;
int map[MAX][MAX];
int color[MAX];

bool    dfs(int cur_v, int v_cnt)
{
    int     i;
    bool    ret = true;

    for (i = 1; i <= v_cnt && ret; ++i)
    {
        if (map[cur_v][i])
        {
            if (color[i] == 0)
            {
                color[i] = (color[cur_v] == BLACK ? WHITE : BLACK);
                ret *= dfs(i, v_cnt);
            }
            else if (color[i] == color[cur_v])
                return (false);
        }
    }
    return (ret);
}

int main(void)
{
    int test_cnt;
    int from, to;
    int v_cnt, e_cnt;
    int possible;

    scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        scanf(" %d %d", &v_cnt, &e_cnt);
        while (e_cnt)
        {
            scanf(" %d %d", &from, &to);
            map[from][to] = 1, map[to][from] = 1;
            --e_cnt;
        }
        possible = 1;
        color[1] = BLACK;
        for (from = 1; from <= v_cnt; ++from)
            if (!dfs(from, v_cnt))
                possible = 0, from = v_cnt + 1;
        if (possible)
            printf("possible\n");
        else
            printf("impossible\n");
        memset(color, 0, sizeof(color));
        memset(map, 0, sizeof(map));
        --test_cnt;
    }
    return (0);
}