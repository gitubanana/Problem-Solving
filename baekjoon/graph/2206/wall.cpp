#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '0',
    WALL = '1'
};

const int   MAX = 1000;

char    visited[MAX][MAX];
char    map[MAX][MAX + 1];
int     y_size, x_size;
int     dy[] = {1, -1, 0, 0};
int     dx[] = {0, 0, -1, 1};
int     bits[] = {1 << 0, 1 << 1};

struct t_pos
{
    int     y, x, cnt;
    bool    has_broken_wall;

    t_pos(int y, int x)
        : y(y), x(x), cnt(1), has_broken_wall(false) { }
    t_pos(int y, int x, int cnt, bool boolean)
        : y(y), x(x), cnt(cnt), has_broken_wall(boolean) { }

    inline bool operator==(const t_pos &other) const {
        return (y == other.y && x == other.x);
    }
};

int bfs(t_pos start, t_pos end)
{
    if (start == end)
        return (1);

    std::queue<t_pos>   q;

    visited[start.y][start.x] |= bits[start.has_broken_wall];
    q.push(start);
    while (!q.empty())
    {
        t_pos   &cur = q.front();
        for (int i = 0; i < 4; ++i)
        {
            t_pos   next(
                        cur.y + dy[i],
                        cur.x + dx[i],
                        cur.cnt,
                        cur.has_broken_wall);

            if (!(0 <= next.y && next.y < y_size)
                || !(0 <= next.x && next.x < x_size))
                continue ;

            char &next_visited = visited[next.y][next.x];
            char &next_space = map[next.y][next.x];

            if (next_space == WALL)
            {
                if (cur.has_broken_wall == true)
                    continue ;
                next.has_broken_wall = true;
            }

            if (next_visited & bits[next.has_broken_wall])
                continue ;

            ++next.cnt;
            if (next == end)
                return (next.cnt);
            next_visited |= bits[next.has_broken_wall];
            q.push(next);
        }
        q.pop();
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> y_size >> x_size;
    for (int y = 0; y < y_size; ++y)
        std::cin >> map[y];

    std::cout << bfs(t_pos(0, 0), t_pos(y_size - 1, x_size - 1)) << '\n';
}
