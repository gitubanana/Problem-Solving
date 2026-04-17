/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

typedef struct s_cnt
{
    int num;
    int cnt;
}   t_cnt;

struct functor
{
    inline bool    operator()(t_cnt a, t_cnt b) const
    {
        return (a.cnt > b.cnt);
    }
};

const int   MAX = 10001;

std::vector<int> map[MAX];
int              visited[MAX];

void    dfs(int cur_v, int &v_cnt, int &cnt)
{
    if (visited[cur_v] == 1)
        return ;
    ++cnt;
    visited[cur_v] = 1;
    for (int i = 0; i < map[cur_v].size(); ++i)
        dfs(map[cur_v][i], v_cnt, cnt);
}

int main()
{
    std::vector<t_cnt>  arr;
    int                 v_cnt, e_cnt;
    int                 from, to, cnt;

    scanf(" %d %d", &v_cnt, &e_cnt);
    while (e_cnt)
    {
        scanf(" %d %d", &to, &from);
        map[from].push_back(to);
        --e_cnt;
    }
    for (from = 1; from <= v_cnt; ++from)
    {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        dfs(from, v_cnt, cnt);
        arr.push_back({from, cnt});
    }
    std::stable_sort(arr.begin(), arr.end(), functor());
    for (from = 0;
        from < arr.size() && arr[from].cnt == arr[0].cnt; ++from)
        printf("%d ", arr[from].num);
    printf("\n");
    return(0);
}
