#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = 0,
    WALL
};

struct t_pos
{
    int y, x;
    bool hasBroken;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][2];

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    in >> input.y >> input.x;
    --input.y, --input.x;
    return (in);
}

inline bool &getVisited(const t_pos &pos)
{
    return (visited[pos.y][pos.x][pos.hasBroken]);
}

int bfs(const t_pos &start, const t_pos &end)
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
                    cur.hasBroken
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || getVisited(next))
                    continue ;

                if (next == end)
                {
                    return (curTime);
                }

                int &nextSpace = map[next.y][next.x];
                if (nextSpace == WALL)
                {
                    if (next.hasBroken)
                        continue ;

                    next.hasBroken = true;
                }

                getVisited(next) = true;
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

    t_pos start, end;

    std::cin >> ySize >> xSize;
    std::cin >> start >> end;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    start.hasBroken = false;
    std::cout << bfs(start, end) << '\n';
    return (0);
}
