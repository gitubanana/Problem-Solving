#include <iostream>
#include <deque>

enum e_space
{
    ICE = 'X',
    MELTING = 'M',
    EMPTY = '.',
    SWAN = 'L'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1500;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE];
int curIdx, nextIdx;
std::deque<t_pos> iceQs[2];
std::deque<t_pos> swanQs[2];

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    putIce(void)
{
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] != EMPTY && map[y][x] != SWAN)
                continue ;

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    y + dy[dir],
                    x + dx[dir]
                };

                if (!isBound(next) || map[next.y][next.x] != ICE)
                    continue ;

                map[next.y][next.x] = MELTING;
                iceQs[curIdx].push_back(next);
            }
        }
    }
}

bool metSwan(void)
{
    std::deque<t_pos> &curQ = swanQs[curIdx];
    std::deque<t_pos> &nextQ = swanQs[nextIdx];

    while (!curQ.empty())
    {
        const t_pos cur = curQ.front();
        curQ.pop_front();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!isBound(next) || visited[next.y][next.x])
                continue ;

            visited[next.y][next.x] = true;
            switch (map[next.y][next.x])
            {
            case SWAN:
                return (true);
            case MELTING:
                nextQ.push_back(next);
                break;
            case EMPTY:
                curQ.push_back(next);
                break;
            }
        }
    }

    return (false);
}

void    meltIce(void)
{
    std::deque<t_pos> &curQ = iceQs[curIdx];
    std::deque<t_pos> &nextQ = iceQs[nextIdx];

    while (!curQ.empty())
    {
        const t_pos cur = curQ.front();
        curQ.pop_front();

        map[cur.y][cur.x] = EMPTY;
        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!isBound(next) || map[next.y][next.x] != ICE)
                continue ;

            map[next.y][next.x] = MELTING;
            nextQ.push_back(next);
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start = {-1, -1};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != -1)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] == SWAN)
            {
                start.y = y, start.x = x;
                break ;
            }
        }
    }

    int day = 0;

    putIce();
    visited[start.y][start.x] = true;
    swanQs[curIdx].push_back(start);
    while (true)
    {
        nextIdx = curIdx ^ 1;

        if (metSwan())
            break ;

        meltIce();

        curIdx = nextIdx;
        ++day;
    }

    std::cout << day << '\n';
    return (0);
}
