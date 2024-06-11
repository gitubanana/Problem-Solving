#include <iostream>
#include <queue>

enum e_space
{
    START = 'S',
    CLIENT = 'C',
    WALL = '#',
    EMPTY = '.'
};

struct t_pos
{
    int y, x;
    int dir;
    int prevDeli;
};

const int MAX = 50;
const int dy[] = {0, -1, 1, 0, 0};
const int dx[] = {0, 0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int visited[3][MAX][MAX];
char map[MAX][MAX + 1];

int bfs(const t_pos &start)
{
    int curTime = 1;
    std::queue<t_pos> q;

    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 1; dir < dirSize; ++dir)
            {
                if (cur.dir == dir)
                    continue ;

                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir],
                    dir,
                    cur.prevDeli,
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL
                    || (visited[next.prevDeli][next.y][next.x] & (1 << next.dir)))
                    continue ;

                visited[next.prevDeli][next.y][next.x] |= (1 << next.dir);
                char &nextSpace = map[next.y][next.x];

                if (std::isdigit(nextSpace)
                    && nextSpace != next.prevDeli + '0')
                {
                    if (next.prevDeli != 0)
                        return (curTime);

                    next.prevDeli = nextSpace - '0';
                }

                q.push(next);
            }
        }
        ++curTime;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int clientCnt = 0;
    t_pos start = {-1, -1, 0, 0};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            switch (map[y][x])
            {
            case START:
                start.y = y, start.x = x;
                break;
            case CLIENT:
                map[y][x] = '0' + (++clientCnt);
                break;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
