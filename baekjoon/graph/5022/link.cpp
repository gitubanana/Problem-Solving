#include <iostream>
#include <climits>
#include <cstring>
#include <queue>

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 101;
const int LINE_CNT = 2;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
bool isWall[MAX_SIZE][MAX_SIZE];
int cameDir[MAX_SIZE][MAX_SIZE];

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    in >> input.x >> input.y;
    return (in);
}

void    makeWall(const t_pos &start, const t_pos &end)
{
    t_pos cur = end;

    isWall[cur.y][cur.x] = true;
    while (true)
    {
        int dir = cameDir[cur.y][cur.x] ^ 1;

        cur.y += dy[dir];
        cur.x += dx[dir];
        isWall[cur.y][cur.x] = true;

        if (cur == start)
            break ;
    }
}

uint32_t bfs(const t_pos &start, const t_pos &end, const t_pos &a, const t_pos &b)
{
    int dist = 1;
    std::queue<t_pos> q;

    memset(cameDir, -1, sizeof(cameDir));
    cameDir[start.y][start.x] = dirSize;
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

                if (!(0 <= next.y && next.y <= ySize)
                    || !(0 <= next.x && next.x <= xSize)
                    || cameDir[next.y][next.x] != -1
                    || isWall[next.y][next.x]
                    || next == a
                    || next == b)
                    continue ;

                cameDir[next.y][next.x] = dir;
                if (next == end)
                {
                    makeWall(start, end);
                    return (dist);
                }

                q.push(next);
            }
        }

        ++dist;
    }

    return (INT_MAX);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start[LINE_CNT];
    t_pos end[LINE_CNT];

    std::cin >> xSize >> ySize;
    for (int i = 0; i < LINE_CNT; ++i)
    {
        std::cin >> start[i] >> end[i];
    }

    int idx = 0;
    uint32_t min = INT_MAX;
    while (true)
    {
        int other = idx ^ 1;
        min = std::min(min,
            bfs(start[idx], end[idx], start[other], end[other])
                + bfs(start[other], end[other], start[idx], end[idx])
        );

        if (++idx == LINE_CNT)
            break ;

        memset(isWall, false, sizeof(isWall));
    }

    if (min == INT_MAX)
        std::cout << "IMPOSSIBLE" << '\n';
    else
        std::cout << min << '\n';
    return (0);
}
