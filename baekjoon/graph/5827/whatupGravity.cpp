#include <iostream>
#include <climits>
#include <deque>

enum e_space
{
    WALL = '#',
    EMPTY = '.',
    START = 'C',
    END = 'D'
};

struct t_pos
{
    int y, x;
    int gravityDir;
};

const int MAX_SIZE = 500;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int cnt[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

inline bool workGravity(t_pos &pos)
{
    if (!isBound(pos) || map[pos.y][pos.x] == WALL)
        return (false);

    do
    {
        if (map[pos.y][pos.x] == END)
            return (true);

        pos.y += dy[pos.gravityDir];
        pos.x += dx[pos.gravityDir];

        if (!isBound(pos))
            return (false);

    } while (map[pos.y][pos.x] != WALL);

    pos.y -= dy[pos.gravityDir];
    pos.x -= dx[pos.gravityDir];
    return (true);
}

int bfs(t_pos &start)
{
    int endCnt = INT_MAX;
    std::deque<t_pos> q;

    if (!workGravity(start))
        return (-1);

    cnt[start.y][start.x] = 1;
    q.push_front(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        const int &curCnt = cnt[cur.y][cur.x];
        q.pop_front();

        if (curCnt >= endCnt)
            continue ;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            if (dir == cur.gravityDir)
                continue ;

            bool newGravity = (dir <= 1);
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                (newGravity ? dir : cur.gravityDir)
            };

            if (!workGravity(next))
                continue ;

            int nextCnt = curCnt + newGravity;
            int &cmpCnt = cnt[next.y][next.x];
            if (!(cmpCnt == 0 || cmpCnt > nextCnt))
                continue ;

            cmpCnt = nextCnt;
            if (map[next.y][next.x] == END)
            {
                endCnt = std::min(endCnt, nextCnt);
                continue ;
            }

            if (newGravity)
            {
                q.push_back(next);
            }
            else
            {
                q.push_front(next);
            }
        }
    }

    return (endCnt == INT_MAX ? -1 : endCnt - 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1, 0};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != -1)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] == START)
            {
                start.y = y, start.x = x;
                break ;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
