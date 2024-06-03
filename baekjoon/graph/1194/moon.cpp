#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = '#',
    START = '0',
    END
};

struct t_pos
{
    int y, x;
    int key;
};

const int FAIL = -1;
const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE][(1 << 6)];

inline bool &getVisited(const t_pos &pos)
{
    return (visited[pos.y][pos.x][pos.key]);
}

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && map[pos.y][pos.x] != WALL
            && !getVisited(pos));
}

inline bool isKey(const char &space)
{
    return ('a' <= space && space <= 'f');
}

inline bool isDoor(const char &space)
{
    return ('A' <= space && space <= 'F');
}

int bfs(const t_pos &start)
{
    int curTime = 1;
    std::queue<t_pos> q;

    getVisited(start) = true;
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

                if (!canGo(next))
                    continue;

                char &nextSpace = map[next.y][next.x];

                getVisited(next) = true;
                if (isKey(nextSpace))
                {
                    next.key |= (1 << (nextSpace - 'a'));
                }
                else if (isDoor(nextSpace))
                {
                    if (!(next.key & (1 << (nextSpace - 'A'))))
                        continue ;
                }
                else if (nextSpace == END)
                {
                    return (curTime);
                }

                q.push(next);
            }
        }

        ++curTime;
    }
    return (FAIL);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {FAIL, FAIL, 0};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != FAIL)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            char &curSpace = map[y][x];

            if (curSpace == START)
            {
                start.y = y, start.x = x;
                curSpace = EMPTY;
                break ;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
