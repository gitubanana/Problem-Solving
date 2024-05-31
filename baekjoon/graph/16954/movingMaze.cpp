#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = '#'
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int SIZE = 8;
const int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
const int dx[] = {0, 0, -1, 1, 1, -1, 1, -1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int visited[SIZE][SIZE];
char map[SIZE][SIZE + 1];

void    moveMaze(void)
{
    for (int y = SIZE - 1; y >= 1; --y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            map[y][x] = map[y - 1][x];
        }
    }

    for (int x = 0; x < SIZE; ++x)
    {
        map[0][x] = EMPTY;
    }
}

inline bool canGo(const t_pos &pos, int curTime)
{
    return ((0 <= pos.y && pos.y < SIZE)
            && (0 <= pos.x && pos.x < SIZE)
            && map[pos.y][pos.x] == EMPTY
            && visited[pos.y][pos.x] != curTime);
}

bool bfs(const t_pos start={SIZE - 1, 0},
            const t_pos end={0, SIZE - 1})
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

            if (map[cur.y][cur.x] == WALL)
                continue ;

            for (int dir = 0; dir < dirSize; ++dir)
            {
                const t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!canGo(next, curTime))
                    continue ;

                if (next == end)
                    return (true);

                visited[next.y][next.x] = curTime;
                q.push(next);
            }
        }

        moveMaze();

        ++curTime;
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int y = 0; y < SIZE; ++y)
    {
        std::cin >> map[y];
    }

    std::cout << bfs() << '\n';
    return (0);
}
