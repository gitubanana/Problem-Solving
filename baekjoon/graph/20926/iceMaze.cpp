#include <iostream>
#include <queue>

enum e_space
{
    START = 'T',
    END = 'E',
    STONE = 'R',
    HOLE = 'H'
};

struct t_pos
{
    int y, x;
    int dir;
    int dist;

    inline bool operator<(const t_pos &other) const
    {
        return (this->dist > other.dist);
    }
};

using t_pq = std::priority_queue<t_pos>;

const int MAX_SIZE = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int dist[dirSize][MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool isBound(int y, int x)
{
    return ((0 <= y && y < ySize)
            && (0 <= x && x < xSize));
}

bool    initPq(t_pq &pq, int startY, int startX)
{    
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = startY + dy[dir];
        int nextX = startX + dx[dir];

        if (!isBound(nextY, nextX))
            continue ;

        char &nextSpace = map[nextY][nextX];
        if (nextSpace == END)
            return (true);

        if (nextSpace == STONE || nextSpace == HOLE)
            continue ;

        dist[dir][nextY][nextX] = nextSpace;
        pq.push({nextY, nextX, dir, nextSpace});
    }
    return (false);
}

bool    pushPq(t_pq &pq, const t_pos &cur, int dir)
{
    t_pos next = {
        cur.y + dy[dir],
        cur.x + dx[dir],
        dir,
        cur.dist
    };

    if (!isBound(next.y, next.x))
        return (false);

    char &nextSpace = map[next.y][next.x];
    if (nextSpace == HOLE || nextSpace == STONE)
        return (false);

    if (nextSpace == END)
        return (true);

    int &nextDist = dist[next.dir][next.y][next.x];

    next.dist += nextSpace;
    if (!(nextDist == 0 || nextDist > next.dist))
        return (false);

    nextDist = next.dist;
    pq.push(next);
    return (false);
}

int dijkstra(int startY, int startX)
{
    t_pq pq;

    if (initPq(pq, startY, startX))
        return (0);
    while (!pq.empty())
    {
        const t_pos cur = pq.top();
        pq.pop();

        if (dist[cur.dir][cur.y][cur.x] != cur.dist)
            continue ;

        int nextY = cur.y + dy[cur.dir];
        int nextX = cur.x + dx[cur.dir];

        if (!isBound(nextY, nextX) || map[nextY][nextX] == HOLE)
            continue ;

        char &nextSpace = map[nextY][nextX];
        if (nextSpace == END)
            return (cur.dist);

        int dir = cur.dir;
        int dirCnt = (nextSpace == STONE ? dirSize : 1);
        while (dirCnt--)
        {
            if (pushPq(pq, cur, dir))
                return (cur.dist);

            dir = (dir + 1) % dirSize;
        }
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int startY = -1, startX;

    std::cin >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            char &curSpace = map[y][x];

            if (std::isdigit(curSpace))
            {
                curSpace -= '0';
            }
            else if (map[y][x] == START)
            {
                startY = y, startX = x;
            }
        }
    }

    std::cout << dijkstra(startY, startX) << '\n';
    return (0);
}
