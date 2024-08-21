#include <iostream>
#include <climits>
#include <queue>
#include <deque>

enum e_space
{
    START = 'V',
    TREE = '+',
    EMPTY = '.',
    END = 'J'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int minDist[MAX_SIZE][MAX_SIZE];
int treeDist[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];
std::queue<t_pos> treeQ;

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    bfs(void)
{
    while (!treeQ.empty())
    {
        const t_pos cur = treeQ.front();
        const int &curDist = treeDist[cur.y][cur.x];
        treeQ.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next)
                || treeDist[next.y][next.x] != 0)
                continue ;

            treeDist[next.y][next.x] = curDist + 1;
            treeQ.push(next);
        }
    }
}

int bfs01(const t_pos &start, const t_pos &end)
{
    std::queue<t_pos> q;
    int endDist = -1;

    minDist[start.y][start.x] = treeDist[start.y][start.x];
    q.push(start);
    while (!q.empty())
    {
        const t_pos cur = q.front();
        const int &curDist = minDist[cur.y][cur.x];
        q.pop();

        if (endDist >= curDist)
            continue ;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next))
                continue ;

            int &cmpDist = minDist[next.y][next.x];
            int nextDist = std::min(curDist, treeDist[next.y][next.x]);
            if (cmpDist >= nextDist)
                continue ;

            cmpDist = nextDist;
            if (map[next.y][next.x] == END)
            {
                endDist = nextDist;
                continue ;
            }

            q.push(next);
        }
    }
    return (endDist - 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start, end;

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
            case END:
                end.y = y, end.x = x;
                break;
            case TREE:
                treeDist[y][x] = 1;
                treeQ.push({y, x});
                break;
            }
        }
    }

    bfs();
    std::cout << bfs01(start, end) << '\n';
    return (0);
}
