#include <iostream>
#include <cstring>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = '#',
    START = '0',
    END = '1'
};

struct t_pos
{
    int y, x;
    int key;
};

const int MAX_SIZE = 50;
const int MAX_KEY = 6;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE][(1 << (MAX_KEY + 1))];

int bfs(const t_pos &start)
{
    int move = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x][start.key] = true;
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
                    cur.key
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x][next.key])
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (nextSpace == END)
                {
                    return (move);
                }
                else if (std::islower(nextSpace))
                {
                    next.key |= (1 << (nextSpace - 'a'));
                }
                else if (std::isupper(nextSpace))
                {
                    if (!(next.key & (1 << (nextSpace - 'A'))))
                        continue ;
                }

                visited[next.y][next.x][next.key] = true;
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

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
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

        memset(visited, false, sizeof(visited));
        std::cout << '#' << t << ' ' << bfs(start) << '\n';
    }
    return (0);
}
