#include <iostream>
#include <queue>
#include <cstring>

struct t_pos
{
    int x, y;
};

const int   MAX = 20;

char    map[MAX][MAX + 1];
int     cnt[MAX][MAX];
const std::string &dir_char = "+-|*";
int     start_idx[] = {0, 0, 2, 4};
int     end_idx[] = {4, 2, 4, 4};

// right, left, up, down
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

void    print_min_intersection(int y_size, int x_size)
{
    int dir_start, dir_end;
    std::queue<t_pos>   q;
    t_pos   cur, next;

    cnt[0][0] = 1;
    q.push({0, 0});
    while (!q.empty())
    {
        cur = q.front(), q.pop();
        char    &dir = map[cur.y][cur.x];
        int     idx = dir_char.find(dir);

        dir_start = start_idx[idx];
        dir_end = end_idx[idx];
        for (; dir_start < dir_end; ++dir_start)
        {
            next.y = cur.y + dy[dir_start];
            next.x = cur.x + dx[dir_start];
            if (!(0 <= next.y && next.y < y_size)
                || !(0 <= next.x && next.x < x_size)
                || cnt[next.y][next.x] > 0
                || map[next.y][next.x] == dir_char[3])
                continue ;
            cnt[next.y][next.x] = cnt[cur.y][cur.x] + 1;
            q.push(next);
        }
    }
    if (cnt[y_size - 1][x_size - 1] > 0
        && map[y_size - 1][x_size - 1] != '*')
        printf("%d\n", cnt[y_size - 1][x_size - 1]);
    else
        printf("-1\n");
}

int main()
{
    int test_cnt;
    int y_size, x_size;

    scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        scanf(" %d %d", &y_size, &x_size);
        for (int y = 0; y < y_size; ++y)
            scanf(" %s", map[y]);
        print_min_intersection(y_size, x_size);
        if (test_cnt > 1)
            memset(cnt, 0, sizeof(cnt));
        --test_cnt;
    }
}
