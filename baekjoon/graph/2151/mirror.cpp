#include <iostream>
#include <queue>
#include <climits>

enum e_space
{
    EMPTY = '.',
    WALL = '*',
    PUTTABLE = '!',
    DOOR = '#'
};

struct t_pos
{
    int y, x;
    int dir;
    int mirrorCnt;

    inline bool operator<(const t_pos &other) const
    {
        return (this->mirrorCnt > other.mirrorCnt);
    }
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
char map[MAX_SIZE][MAX_SIZE + 1];
int cnt[dirSize][MAX_SIZE][MAX_SIZE];

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size)
            && map[pos.y][pos.x] != WALL);
}

inline int getNextDir(int curDir, int dd)
{
    int nextDir = curDir + dd;

    if (nextDir == -1)
        return (dirSize - 1);

    return (nextDir % dirSize);
}

int bfs(int startY, int startX)
{
    std::priority_queue<t_pos> q;

    map[startY][startX] = WALL;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos next = {
            startY + dy[dir],
            startX + dx[dir],
            dir,
            0
        };

        if (!canGo(next))
            continue ;

        if (map[next.y][next.x] == DOOR)
            return (0);

        cnt[next.dir][next.y][next.x] = 0;
        q.push(next);
    }

    int endCnt = INT_MAX;
    while (!q.empty())
    {
        const t_pos cur = q.top();
        q.pop();

        if (cnt[cur.dir][cur.y][cur.x] != cur.mirrorCnt
            || endCnt <= cur.mirrorCnt)
            continue ;

        bool isPuttable = (map[cur.y][cur.x] == PUTTABLE);
        int startD = -1 * isPuttable;
        int endD = 1 * isPuttable;
        for (int dd = startD; dd <= endD; ++dd)
        {
            int nextDir = getNextDir(cur.dir, dd);
            t_pos next = {
                cur.y + dy[nextDir],
                cur.x + dx[nextDir],
                nextDir,
                cur.mirrorCnt + (dd != 0)
            };

            if (!canGo(next))
                continue ;

            if (map[next.y][next.x] == DOOR)
            {
                endCnt = next.mirrorCnt;
                continue ;
            }

            int &nextCnt = cnt[next.dir][next.y][next.x];
            if (!(nextCnt == 0 || nextCnt > next.mirrorCnt))
                continue;

            nextCnt = next.mirrorCnt;
            q.push(next);
        }
    }
    return (endCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int startY = -1, startX;

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];
        if (startY != -1)
            continue ;

        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] == DOOR)
            {
                startY = y, startX = x;
                break ;
            }
        }
    }

    std::cout << bfs(startY, startX) << '\n';
    return (0);
}
