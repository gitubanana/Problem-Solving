#include <iostream>
#include <queue>
#include <climits>

enum e_space
{
    EMPTY = 0,
    WALL,
    SWORD
};

struct t_pos
{
    int y, x;
};

const int FAIL = INT_MAX;
const int MAX_SIZE = 100;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, timeLimit;
int map[MAX_SIZE][MAX_SIZE];

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && map[pos.y][pos.x] != WALL);
}

inline bool isEnd(const t_pos &pos)
{
    return (pos.y == ySize - 1
            && pos.x == xSize - 1);
}

inline int endDist(const t_pos &pos)
{
    return ((ySize - 1 - pos.y)
            + (xSize - 1 - pos.x));
}

int bfs(t_pos start={0, 0})
{
    int curTime = 1;
    int swordTime = FAIL;
    std::queue<t_pos> q;

    map[start.y][start.x] = WALL;
    q.push(start);
    while (curTime <= timeLimit
            && !q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!canGo(next))
                    continue ;

                int &nextSpace = map[next.y][next.x];
                if (nextSpace == SWORD)
                {
                    swordTime = curTime + endDist(next);
                }
                else if (isEnd(next))
                {
                    return std::min(curTime, swordTime);
                }

                nextSpace = WALL;
                q.push(next);
            }
        }
        ++curTime;
    }
    return (swordTime > timeLimit ? FAIL : swordTime);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> timeLimit;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int saveTime = bfs();
    if (saveTime == FAIL)
    {
        std::cout << "Fail" << '\n';
    }
    else
    {
        std::cout << saveTime << '\n';
    }
    return (0);
}
