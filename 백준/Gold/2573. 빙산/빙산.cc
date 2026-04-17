#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

struct t_pos
{
    int y;
    int x;
};

enum e_space
{
    EMPTY
};

typedef std::vector<t_pos>  t_vec;

const int   MAX = 300;

int map[MAX][MAX];
int visited[MAX][MAX];
int y_size, x_size;
int ans;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void    dfs(int y, int x)
{
    visited[y][x] = 1;

    int next_y, next_x;
    for (int i = 0; i < 4; ++i)
    {
        next_y = y + dy[i];
        next_x = x + dx[i];
        if (!(1 <= next_y && next_y < y_size)
            || !(1 <= next_x && next_x < x_size)
            || map[next_y][next_x] == EMPTY
            || visited[next_y][next_x])
            continue ;
        dfs(next_y, next_x);
    }
}

int count_chunk(void)
{
    int y, x;
    int ret = 0;

    memset(visited, 0, sizeof(visited));
    for (y = 1; y < y_size; ++y)
    {
        for (x = 1; x < x_size; ++x)
        {
            if (map[y][x] != EMPTY && !visited[y][x])
                dfs(y, x), ++ret;
            if (ret == 2)
                return (ret);
        }
    }
    memset(visited, 0, sizeof(visited));
    return (ret);
}

void    print_map(void)
{
    int y, x;
    
    printf("================================");
    for (y = 1; printf("\n") && y < y_size; ++y)
    {
        for (x = 1; x < x_size; ++x)
        {
            printf("%d ", map[y][x]);
        }
    }
    printf("================================\n");
}

void bfs(t_vec &pos_vec)
{
    int i;
    std::queue<t_pos>   q;
    t_pos   cur_pos, around;
    int melt_cnt, height, q_size, year;

    for (i = 0; i < pos_vec.size(); ++i)
        q.push(pos_vec[i]);
    year = 0;
    while (!q.empty())
    {
        q_size = q.size();
        while (q_size--)
        {
            melt_cnt = 0;
            cur_pos = q.front(), q.pop();
            visited[cur_pos.y][cur_pos.x] = 1;
            for (i = 0; i < 4; ++i)
            {
                around.y = cur_pos.y + dy[i];
                around.x = cur_pos.x + dx[i];
                if (map[around.y][around.x] == EMPTY
                    && !visited[around.y][around.x])
                    ++melt_cnt;
            }
            height = map[cur_pos.y][cur_pos.x] - melt_cnt;
            if (height <= 0)
                map[cur_pos.y][cur_pos.x] = EMPTY;
            else
            {
                map[cur_pos.y][cur_pos.x] = height;
                q.push(cur_pos);
            }
        }
        ++year;
        if (count_chunk() >= 2)
        {
            ans = year;
            return ;
        }
    }
}

int main(void)
{
    int y, x;
    t_vec   pos_vec;

    scanf(" %d %d", &y_size, &x_size);
    for (y = 0; y < y_size; ++y)
    {
        for (x = 0; x < x_size; ++x)
        {
            scanf(" %d", &map[y][x]);
            if (map[y][x] != EMPTY)
                pos_vec.push_back({y, x});
        }
    }
    --y_size, --x_size;
    bfs(pos_vec);
    printf("%d\n", ans);
    return 0;
}
