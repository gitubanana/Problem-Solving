#include <iostream>
#include <queue>

enum e_space
{
    START = 'S',
    END = 'H',
    WALL = 'X'
};

struct t_pos
{
    int y, x;
    int backDir;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 0, 1, 0, 0};
const int dx[] = {0, -1, 0, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]) - 1;

int ySize, xSize, misfortuneLimit;
bool visited[MAX_SIZE][MAX_SIZE][dirSize];
char map[MAX_SIZE][MAX_SIZE + 1];

inline int getOppisite(int dir)
{
    return ((dir + 2) % dirSize);
}

inline bool canGo(int nextY, int nextX, int dir)
{
    return ((0 <= nextY && nextY < ySize)
            && (0 <= nextX && nextX < xSize)
            && map[nextY][nextX] != WALL
            && !visited[nextY][nextX][dir]);
}

inline bool isMisfortune(const char &space)
{
    return (0 <= space && space <= 9);
}

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
            const int curMisfortune =
                        map[cur.y][cur.x]
                        + map[cur.y + dy[cur.backDir]][cur.x + dx[cur.backDir]];
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                if (dir == cur.backDir)
                    continue ;

                int nextY = cur.y + dy[dir];
                int nextX = cur.x + dx[dir];
                if (!canGo(nextY, nextX, dir))
                    continue ;

                char &nextSpace = map[nextY][nextX];
                if (isMisfortune(nextSpace))
                {
                    if (curMisfortune + nextSpace > misfortuneLimit)
                        continue ;

                    visited[nextY][nextX][dir] = true;
                    q.push({nextY, nextX, getOppisite(dir)});
                }
                else if (nextSpace == END)
                {
                    return (curTime);
                }
            }
        }
        ++curTime;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1, dirSize};

    std::cin >> ySize >> xSize >> misfortuneLimit;
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
            else if (curSpace == START)
            {
                start.y = y, start.x = x;
                curSpace = 0;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
