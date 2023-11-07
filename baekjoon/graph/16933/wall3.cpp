#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '0',
    WALL = '1'
};

const int   NIGHT = 1;
const int   MAX = 1000;

int     visited[MAX][MAX];
char    map[MAX][MAX + 1];
int     y_size, x_size, break_cnt;
int     dy[] = {1, -1, 0, 0};
int     dx[] = {0, 0, -1, 1};
int     bits[] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4,
                  1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10};

struct t_pos
{
    int y, x, cnt;
    int broken_cnt;

    t_pos(int y, int x)
        : y(y), x(x), cnt(1), broken_cnt(0) { }
    t_pos(int y, int x, int cnt, int broken_cnt)
        : y(y), x(x), cnt(cnt), broken_cnt(broken_cnt) { }

    inline bool operator==(const t_pos &other) const {
        return (y == other.y && x == other.x);
    }
};

int bfs(t_pos start, t_pos end)
{
    if (start == end)
        return (1);

    int time = 0;
    std::queue<t_pos>   q;

    visited[start.y][start.x] |= bits[start.broken_cnt];
    q.push(start);
    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size--)
        {
            t_pos   &cur = q.front();
            for (int i = 0; i < 4; ++i)
            {
                t_pos   next(
                            cur.y + dy[i],
                            cur.x + dx[i],
                            cur.cnt,
                            cur.broken_cnt);
    
                if (!(0 <= next.y && next.y < y_size)
                    || !(0 <= next.x && next.x < x_size))
                    continue ;
    
                int &next_visited = visited[next.y][next.x];
                char &next_space = map[next.y][next.x];

                if (next_space == WALL)
                {
                    if (time & NIGHT)
                    {
                        q.push({cur.y, cur.x, cur.cnt + 1, cur.broken_cnt});
                        continue ;
                    }
                    if (cur.broken_cnt == break_cnt)
                        continue ;
                    ++next.broken_cnt;
                }
    
                if (next_visited & bits[next.broken_cnt])
                    continue ;
    
                ++next.cnt;
                if (next == end)
                    return (next.cnt);
                next_visited |= bits[next.broken_cnt];
                q.push(next);
            }
            q.pop();
        }
        ++time;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> y_size >> x_size >> break_cnt;
    for (int y = 0; y < y_size; ++y)
        std::cin >> map[y];

    std::cout << bfs(t_pos(0, 0), t_pos(y_size - 1, x_size - 1)) << '\n';
}
