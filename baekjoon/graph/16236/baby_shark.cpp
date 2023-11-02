#include <iostream>
#include <queue>
#include <cstring>
#include <climits>

struct t_pos
{
    int y, x;

    t_pos(void) : y(0), x(0) {}
    t_pos(int _y, int _x) : y(_y), x(_x) {}
};

const int   MAX = 20;
const int   EMPTY = 0;
const int   BABY_SHARK = 9;
const int   FISH_MAX_SIZE = 6;

int  size;
int  map[MAX][MAX];
bool visited[MAX][MAX];

bool bfs(t_pos &start, int baby_size, int &sec)
{
    static const int  dy[] = {-1, 0, 1, 0};
    static const int  dx[] = {0, -1, 0, 1};
    std::queue<t_pos> q;
    int               plus_sec = 0;
    bool              has_found = false;
    t_pos             end = {INT_MAX, INT_MAX};

    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        int q_size = q.size();
        while (q_size--)
        {
            t_pos &cur = q.front();

            for (int i = 0; i < 4; ++i)
            {
                t_pos   next(cur.y + dy[i],
                            cur.x + dx[i]);

                if (!(0 <= next.y && next.y < size)
                    || !(0 <= next.x && next.x < size)
                    || visited[next.y][next.x] == true
                    || map[next.y][next.x] > baby_size)
                    continue ;

                if (map[next.y][next.x] != EMPTY
                    && map[next.y][next.x] < baby_size)
                {
                    if (end.y > next.y)
                        end = next;
                    else if (end.y == next.y)
                    {
                        if (end.x > next.x)
                            end = next;
                    }
                    has_found = true;
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
            q.pop();
        }
        ++plus_sec;
        if (has_found)
        {
            map[start.y][start.x] = 0;
            start = end;
            sec += plus_sec;
            return (true);
        }
    }
    return (false);
}

void    simulation(t_pos &baby_pos)
{
    int sec = 0;
    int ate_cnt = 0;
    int baby_size = 2;

    while (1)
    {
        if (bfs(baby_pos, baby_size, sec) == false)
            break ;

        memset(visited, 0, sizeof(visited));
        ++ate_cnt;
        if (ate_cnt == baby_size)
            ++baby_size, ate_cnt = 0;
    }
    std::cout << sec << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start;

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int   &cur_space = map[y][x];

            std::cin >> cur_space;
            if (cur_space == BABY_SHARK)
                start = {y, x};
        }
    }

    simulation(start);

    return (0);
}
