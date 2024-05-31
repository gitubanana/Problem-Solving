#include <iostream>
#include <queue>
#include <unordered_set>

enum e_space
{
    EMPTY = '.',
    WALL = '#',
    START = 'S',
    STOPOVER = 'X',
    END = 'E'
};

struct t_pos
{
    int y, x;
    int stopover;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

using t_umap = std::unordered_set<int>;

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
t_umap visited[MAX_SIZE][MAX_SIZE];
t_pos start;
int stopoverCnt;

inline bool canGo(const t_pos &pos)
{
    t_umap &curVisited = visited[pos.y][pos.x];

    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && map[pos.y][pos.x] != WALL
            && curVisited.find(pos.stopover) == curVisited.end());
}

inline bool isStopOver(char &space)
{
    return (0 <= space && space < stopoverCnt);
}

inline bool isEnd(char &space, int stopover)
{
    static const int endStopover = (1 << stopoverCnt) - 1;

    return (space == END
            && stopover == endStopover);
}

int bfs()
{
    int curTime = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x].insert(start.stopover);
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
                    cur.stopover
                };

                if (!canGo(next))
                    continue ;

                char &nextSpace = map[next.y][next.x];
                t_umap &nextVisited = visited[next.y][next.x];

                nextVisited.insert(next.stopover);
                if (isStopOver(nextSpace))
                {
                    next.stopover |= (1 << nextSpace);
                }
                else if (isEnd(nextSpace, next.stopover))
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


    std::cin >> xSize >> ySize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];

        for (int x = 1; x < xSize; ++x)
        {
            char &curSpace = map[y][x];

            switch (curSpace)
            {
            case START:
                start.y = y, start.x = x;
                break;
            case STOPOVER:
                curSpace = stopoverCnt++;
                break; 
            }
        }
    }

    std::cout << bfs() << '\n';
    return (0);
}
