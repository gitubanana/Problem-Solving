#include <iostream>
#include <cstring>
#include <queue>

enum e_space
{
    CLEAN = '.',
    DIRTY = '*',
    WALL = 'x',
    START = 'o'
};

struct t_pos
{
    int y, x;
    int cleaned;
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[(1 << 11)][MAX_SIZE][MAX_SIZE];

int bfs(const t_pos &start, int allCleaned)
{
    int curTime = 1;
    std::queue<t_pos> q;

    visited[start.cleaned][start.y][start.x] = true;
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
                    cur.x + dx[dir],
                    cur.cleaned
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL
                    || visited[next.cleaned][next.y][next.x])
                    continue ;

                visited[next.cleaned][next.y][next.x] = true;

                char &nextSpace = map[next.y][next.x];
                if (0 <= nextSpace && nextSpace <= 9)
                {
                    next.cleaned |= (1 << nextSpace);
                }

                if (next.cleaned == allCleaned)
                {
                    return (curTime);
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

    while (true)
    {
        std::cin >> xSize >> ySize;
        if (ySize == 0)
            break ;

        int dirtyCnt = 0;
        t_pos start = {-1, -1, 0};
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
                case DIRTY:
                    map[y][x] = dirtyCnt++;
                    break;
                }
            }
        }

        std::cout << bfs(start, (1 << dirtyCnt) - 1) << '\n';
        memset(visited, false, sizeof(visited));
    }
    return (0);
}
