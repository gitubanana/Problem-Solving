#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '0',
    WALL,
    END,
    MANNEQUIN,
    START
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 2000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE];
bool scary[MAX_SIZE][MAX_SIZE];
std::queue<t_pos> mQ;

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && !scary[pos.y][pos.x]);
}

void    setScary(int dist)
{
    while (!mQ.empty() && dist--)
    {
        int qSize = mQ.size();
        while (qSize--)
        {
            const t_pos cur = mQ.front();
            mQ.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!canGo(next))
                    continue ;

                scary[next.y][next.x] = true;
                mQ.push(next);
            }
        }
    }
}

int bfs(const t_pos &start)
{

    int move = 1;
    std::queue<t_pos> q;

    scary[start.y][start.x] = true;
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
                    cur.x + dx[dir]
                };

                if (!canGo(next))
                    continue ;

                char &nextSpace = map[next.y][next.x];
                switch (nextSpace)
                {
                case END:
                    return (move);
                case EMPTY:
                    scary[next.y][next.x] = true;
                    q.push(next);
                    break;
                }

            }
        }

        ++move;
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int dist;
    t_pos start;

    std::cin >> ySize >> xSize >> dist;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];

            std::cin >> space;
            switch (space)
            {
            case START:
                start.y = y, start.x = x;
                break;
            case MANNEQUIN:
                scary[y][x] = true;
                mQ.push({y, x});
                break;
            }
        }
    }

    setScary(dist);
    std::cout << bfs(start) << '\n';
    return (0);
}
