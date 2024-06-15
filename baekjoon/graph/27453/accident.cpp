#include <iostream>
#include <deque>
#include <queue>

enum e_space
{
    START = 'S',
    END = 'H',
    WALL = 'X'
};

struct t_mishap
{
    static const int SIZE = 3;

    int badNum[SIZE];
    int total, end;

    t_mishap(void) : total(0), end(0)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            badNum[i] = 0;
        }
    }

    inline void push(int num)
    {
        int idx = end % SIZE;

        total -= badNum[idx];
        total += num;
        badNum[idx] = num;
        ++end;
    }
};

struct t_pos
{
    int y, x;
    int backDir;
    t_mishap misfortune;
};

const int MAX_SIZE = 1000;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, mishapLimit;
bool visited[MAX_SIZE][MAX_SIZE][dirSize];
char map[MAX_SIZE][MAX_SIZE + 1];

inline int getOppisite(int dir)
{
    return ((dir + 2) % dirSize);
}

inline bool canGo(int nextY, int nextX, int accident, int dir)
{
    return ((0 <= nextY && nextY < ySize)
            && (0 <= nextX && nextX < xSize)
            && map[nextY][nextX] != WALL
            && !visited[nextY][nextX][dir]);
}

int bfs(const t_pos &start)
{
    int curTime = 1;
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
                if (dir == cur.backDir)
                    continue ;

                int nextY = cur.y + dy[dir];
                int nextX = cur.x + dx[dir];

                if (!canGo(nextY, nextX, cur.misfortune.total, dir))
                    continue ;

                char &nextSpace = map[nextY][nextX];
                if (std::isdigit(nextSpace))
                {
                    int plusMisfortune = nextSpace - '0';
                    t_mishap nextMishap = cur.misfortune;

                    nextMishap.push(plusMisfortune);
                    if (nextMishap.total > mishapLimit)
                        continue ;

                    visited[nextY][nextX][dir] = true;
                    q.push({nextY, nextX, getOppisite(dir), nextMishap});
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

    t_pos start = {-1, -1, -1, t_mishap()};

    std::cin >> ySize >> xSize >> mishapLimit;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (start.y != -1)
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            if (map[y][x] == START)
            {
                start.y = y, start.x = x;
                break ;
            }
        }
    }

    std::cout << bfs(start) << '\n';
    return (0);
}
