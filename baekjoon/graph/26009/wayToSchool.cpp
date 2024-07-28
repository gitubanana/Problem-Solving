#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 3000;

int ySize, xSize;
bool trafficJam[MAX_SIZE][MAX_SIZE];

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && !trafficJam[pos.y][pos.x]);
}

inline void    setJam(const t_pos &pos)
{
    if (!canGo(pos))
        return ;

    trafficJam[pos.y][pos.x] = true;
}

void    drawCircle(int y, int x, int r)
{
    static const int dy[] = {1, 1, -1, -1};
    static const int dx[] = {1, -1, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    if (r == 0)
    {
        setJam({y, x});
        return ;
    }

    t_pos vertex[] = {
        {y - r, x},
        {y, x + r},
        {y + r, x},
        {y, x - r}
    };

    int dir = 0;
    int vCnt = 4;
    t_pos cur = vertex[dir];
    while (vCnt--)
    {
        int nextDir = (dir + 1) % dirSize;
        while (true)
        {
            if (cur == vertex[nextDir])
                break ;

            setJam(cur);
            cur.y += dy[dir];
            cur.x += dx[dir];
        }

        dir = nextDir;
    }
}

int bfs(const t_pos &start, const t_pos &end)
{
    static const int dy[] = {-1, 1, 0, 0};
    static const int dx[] = {0, 0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    int move = 1;
    std::queue<t_pos> q;

    trafficJam[start.y][start.x] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!canGo(next))
                    continue ;

                if (next == end)
                {
                    return (move);
                }

                trafficJam[next.y][next.x] = true;
                q.push(next);
            }
        }

        ++move;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int jamCnt;

    std::cin >> ySize >> xSize >> jamCnt;
    while (jamCnt--)
    {
        int y, x, r;

        std::cin >> y >> x >> r;
        drawCircle(y - 1, x - 1, r);
    }

    int minMove =  bfs({0, 0}, {ySize - 1, xSize - 1});
    if (minMove == -1)
    {
        std::cout << "NO" << '\n';
    }
    else
    {
        std::cout << "YES" << '\n';
        std::cout << minMove << '\n';
    }
    return (0);
}
