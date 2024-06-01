#include <iostream>
#include <queue>

enum e_space
{
    START = 'A',
    END = 'B',
    WALL = '.',
    ROAD = '#'
};

struct t_pos
{
    int y, x;
};

struct t_light
{
    static const int TIME_CNT = 2;

    int time_[TIME_CNT];
    int startIdx; // 0 -> (east and west), 1 -> (south and north)
    int period;

    inline bool canEnterFrom(int enterDir, int curTime)
    {
        curTime = curTime % period;
        enterDir /= 2;

        if (curTime < time_[startIdx])
        {
            return (startIdx == enterDir);
        }
        return (startIdx != enterDir);
    }
};

const int FAIL = -1;
const int MAX_SIZE = 20;
const int MAX_LIGHT_CNT = 10;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, lightCnt;
t_light lights[MAX_LIGHT_CNT];
char map[MAX_SIZE][MAX_SIZE + 1];

inline std::istream &operator>>(std::istream &in, t_light &input)
{
    char ch;

    in >> ch;
    input.startIdx = (ch == '|');
    input.period = 0;
    for (int i = 0; i < t_light::TIME_CNT; ++i)
    {
        int &curTime = input.time_[i];

        in >> curTime;
        input.period += curTime;
    }
    return (in);
}

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize)
            && map[pos.y][pos.x] != WALL);
}

int bfs(const t_pos &start)
{
    int curTime = 0;
    std::queue<t_pos> q;

    map[start.y][start.x] = WALL;
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
                const t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!canGo(next))
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (std::isdigit(nextSpace)
                    && !lights[nextSpace - '0'].canEnterFrom(dir, curTime))
                {
                    q.push(cur);
                    continue ;
                }

                if (nextSpace == END)
                {
                    return (curTime + 1);
                }

                nextSpace = WALL;
                q.push(next);
            }
        }

        ++curTime;
    }

    return (FAIL);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        std::cin >> ySize >> xSize;
        if (ySize == 0)
            break ;

        t_pos start;

        lightCnt = 0;
        for (int y = 0; y < ySize; ++y)
        {
            std::cin >> map[y];

            for (int x = 0; x < xSize; ++x)
            {
                char &curSpace = map[y][x];

                if (curSpace == START)
                {
                    start = {y, x};
                }
                else if (std::isdigit(curSpace))
                {
                    ++lightCnt;
                }
            }
        }

        int idx;
        for (int i = 0; i < lightCnt; ++i)
        {
            std::cin >> idx >> lights[idx];
        }

        int timeToGo = bfs(start);
        if (timeToGo == FAIL)
        {
            std::cout << "impossible" << '\n';
        }
        else
        {
            std::cout << timeToGo << '\n';
        }
    }
    return (0);
}
