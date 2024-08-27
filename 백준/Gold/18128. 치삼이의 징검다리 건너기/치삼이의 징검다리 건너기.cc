#include <iostream>
#include <queue>

enum e_space
{
    LAND = '0',
    STONE
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 1000;

int size;
char map[MAX_SIZE][MAX_SIZE + 1];
bool isCool[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
std::queue<t_pos> waterQ;
int curIdx, nextIdx;
std::queue<t_pos> catQ[2];

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

void    moveWater(void)
{
    static const int dy[] = {-1, 1, 0, 0};
    static const int dx[] = {0, 0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    int qSize = waterQ.size();

    while (qSize--)
    {
        const t_pos cur = waterQ.front();
        waterQ.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next)
                || isCool[next.y][next.x])
                continue ;

            isCool[next.y][next.x] = true;
            waterQ.push(next);
        }
    }
}

bool    moveCat(void)
{
    static const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    static const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);
    static const t_pos end = {size - 1, size - 1};

    std::queue<t_pos> &curQ = catQ[curIdx];
    std::queue<t_pos> &nextQ = catQ[nextIdx];

    while (!curQ.empty())
    {
        int stoneCnt = 0, goCnt = 0;
        const t_pos cur = curQ.front();
        curQ.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!inRange(next)
                || visited[next.y][next.x]
                || map[next.y][next.x] != STONE)
                continue ;

            if (next == end)
                return (true);

            ++stoneCnt;
            if (!isCool[next.y][next.x])
                continue ;

            ++goCnt;
            visited[next.y][next.x] = true;
            curQ.push(next);
        }

        if (stoneCnt != goCnt)
            nextQ.push(cur);
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int waterCnt;
    const t_pos start = {0, 0};

    std::cin >> size >> waterCnt;
    while (waterCnt--)
    {
        t_pos pos;

        std::cin >> pos.y >> pos.x;
        --pos.y, --pos.x;

        isCool[pos.y][pos.x] = true;
        waterQ.push(pos);
    }

    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];
    }

    int day = 0;
    bool success = false;

    visited[start.y][start.x] = true;
    catQ[curIdx].push(start);
    do
    {
        nextIdx = curIdx ^ 1;
        if (moveCat())
        {
            success = true;
            break ;
        }
        curIdx = nextIdx;

        moveWater();
        ++day;
    } while (!catQ[curIdx].empty());

    std::cout << (success ? day : -1) << '\n';
    return (0);
}
