#include <iostream>
#include <climits>
#include <queue>

enum e_space
{
    START = 'S',
    END = 'F',
    GARBAGE = 'g',
    EMPTY = '.'
};

struct t_stat
{
    int passed;
    int grazed;

    inline bool operator<(const t_stat &other) const
    {
        if (this->passed == other.passed)
            return (this->grazed > other.grazed);

        return (this->passed > other.passed);
    }

    inline bool operator==(const t_stat &other) const
    {
        return (this->passed == other.passed && this->grazed == other.grazed);
    }

    inline bool operator<=(const t_stat &other) const
    {
        return (*this < other || *this == other);
    }
};

struct t_coordinate
{
    int y, x;
};

struct t_pos : public t_stat, public t_coordinate
{
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
t_stat stat[MAX_SIZE][MAX_SIZE];
bool nearGarbage[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

inline bool inRange(const t_coordinate &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    bfs(const t_pos &start)
{
    t_stat endStat = {INT_MAX, INT_MAX};
    std::priority_queue<t_pos> pq;

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            stat[y][x] = {INT_MAX, INT_MAX};
        }
    }

    stat[start.y][start.x] = {0, 0};
    pq.push(start);
    while (!pq.empty())
    {
        const t_pos cur = pq.top();
        pq.pop();

        if (cur <= endStat)
            continue ;

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.passed,
                cur.grazed,
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next))
                continue ;

            char &nextSpace = map[next.y][next.x];

            switch (nextSpace)
            {
            case END:
                if (endStat < next)
                    endStat = next;
                continue;
            case GARBAGE:
                ++next.passed;
                break;
            default:
                next.grazed += nearGarbage[next.y][next.x];
                break;
            }

            t_stat &cmp = stat[next.y][next.x];
            if (cmp < next)
            {
                cmp = next;
                pq.push(next);
            }
        }
    }

    std::cout << endStat.passed << ' ';
    std::cout << endStat.grazed << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {0, 0, -1, -1};

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
                    break ;
                case GARBAGE:
                    for (int dir = 0; dir < dirSize; ++dir)
                    {
                        t_coordinate next = {
                            y + dy[dir],
                            x + dx[dir]
                        };

                        if (!inRange(next))
                            continue ;          

                        nearGarbage[next.y][next.x] = true;
                    }
                    break;
            }
        }
    }

    bfs(start);
    return (0);
}
