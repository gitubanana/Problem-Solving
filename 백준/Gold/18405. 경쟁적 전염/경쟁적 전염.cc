#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

typedef struct s_pos
{
    int y;
    int x;
}   t_pos;


typedef struct s_virus
{
    t_pos   pos;
    int     virus_num;
    
    bool    operator<(struct s_virus b)
    {
        return (this->virus_num < b.virus_num);
    }
}   t_virus;

const int   MAX = 200;

int         map[MAX][MAX];
// up, down, left, right
int         dy[] = {-1, 1, 0, 0};
int         dx[] = {0, 0, 1, -1};

void    bfs(int &size, int &v_cnt, int &sec, std::vector<t_virus> &arr)
{
    std::queue<t_pos>   q;
    int                 i, ran_one_cycle;
    t_pos               cur_pos, next_pos;

    for (i = 0; i < arr.size(); ++i)
        q.push(arr[i].pos);
    ran_one_cycle = 0;
    while (!q.empty() && sec)
    {
        cur_pos = q.front(), q.pop();
        if (!ran_one_cycle && map[cur_pos.y][cur_pos.x] == v_cnt)
            ran_one_cycle = 1, --sec;
        else if (ran_one_cycle && map[cur_pos.y][cur_pos.x] != v_cnt)
            ran_one_cycle = 0;
        for (i = 0; i < 4; ++i)
        {
            next_pos.y = cur_pos.y + dy[i];
            next_pos.x = cur_pos.x + dx[i];
            if (!(0 <= next_pos.y && next_pos.y < size)
                || !(0 <= next_pos.x && next_pos.x < size)
                || map[next_pos.y][next_pos.x] != 0)
                continue ;
            q.push(next_pos);
            map[next_pos.y][next_pos.x] = map[cur_pos.y][cur_pos.x];
        }
    }
}

int main(void)
{
    t_pos                   end;
    int                     y, x, size, v_cnt, sec;
    std::vector<t_virus>    arr;

    scanf(" %d %d", &size, &v_cnt);
    for (y = 0; y < size; ++y)
    {
        for (x = 0; x < size; ++x)
        {
            scanf(" %d", &map[y][x]);
            if (map[y][x] != 0)
                arr.push_back({{y, x}, map[y][x]});
        }
    }
    scanf(" %d %d %d", &sec, &end.y, &end.x);
    std::sort(arr.begin(), arr.end());
    bfs(size, v_cnt, sec, arr);
    printf("%d\n", map[end.y - 1][end.x - 1]);
    return (0);
}