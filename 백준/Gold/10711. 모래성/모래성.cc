#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '.'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
std::queue<t_pos> q;

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

int bfs(void)
{
    int curTime = -1;

    while (!q.empty())
    {
        int qSize = q.size();

        ++curTime;
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

                if (!inRange(next)
                    || map[next.y][next.x] == EMPTY)
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (--nextSpace == 0)
                {
                    nextSpace = EMPTY;
                    q.push(next);
                }
            }
        }
    }

    return (curTime);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 0; x < xSize; ++x)
        {
            char &curSpace = map[y][x];

            if (curSpace == EMPTY)
            {
                q.push({y, x});
            }
            else
            {
                curSpace -= '0';
            }
        }
    }

    std::cout << bfs() << '\n';
    return (0);
}
