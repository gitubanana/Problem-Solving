#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef struct s_cnt
{
    int num;
    int cnt;
}   t_cnt;

struct Functor
{
    bool operator()(t_cnt a, t_cnt b) const
    {
        return (a.cnt > b.cnt);
    }
};

const int   MAX = 20001;

std::vector<int>    map[MAX];
t_cnt                 cnt[MAX];

void    bfs(int start)
{
    std::queue<int> q;
    int             i, cur_pos, next_pos;

    cnt[start].cnt = 1;
    q.push(start);
    while (!q.empty())
    {
        cur_pos = q.front(), q.pop();
        for (i = 0; i < map[cur_pos].size(); ++i)
        {
            next_pos = map[cur_pos][i];
            if (cnt[next_pos].cnt == 0)
            {
                cnt[next_pos].cnt = cnt[cur_pos].cnt + 1;
                q.push(next_pos);
            }
        }
    }
}

int main()
{
    int i, from, to;
    int v_cnt, e_cnt, equal_cnt;

    scanf(" %d %d", &v_cnt, &e_cnt);
    while (e_cnt)
    {
        scanf(" %d %d", &from, &to);
        map[from].push_back(to);
        map[to].push_back(from);
        --e_cnt;
    }
    bfs(1);
    for (i = 1; i <= v_cnt; ++i)
        cnt[i].num = i;
    std::stable_sort(cnt + 1, cnt + 1 + v_cnt, Functor());
    for (i = 2, equal_cnt = 1;
            i <= v_cnt && cnt[1].cnt == cnt[i].cnt; ++i)
        ++equal_cnt;
    printf("%d %d %d\n", cnt[1].num, cnt[1].cnt - 1, equal_cnt);
    return 0;
}