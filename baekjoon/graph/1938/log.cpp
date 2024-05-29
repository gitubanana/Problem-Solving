#include <iostream>
#include <algorithm>
#include <queue>

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[2][MAX_SIZE][MAX_SIZE];

enum e_space
{
    EMPTY = '0',
    WALL = '1',
    BEGIN = 'B',
    END = 'E'
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (y == other.y && x == other.x);
    }

    inline bool canGo(void) const
    {
        return ((0 <= y && y < size)
                && (0 <= x && x < size)
                && map[y][x] == EMPTY);
    }
};

struct t_log
{
    static const int SIZE = 3;
    static const int VERTICAL = 0;
    static const int HORIZONTAL = 2;

    int dir; // 0 -> (up and down), 1 -> (left and right)
    t_pos center;

    t_log(t_pos arr[SIZE])
    {
        center = arr[SIZE / 2];
        dir = (arr[0].y == arr[1].y) * 2;
    }

    inline bool move(int moveDir)
    {
        int checkCnt = SIZE - 1;
        int checkDir = dir;

        while (checkCnt--)
        {
            t_pos check = {
                center.y + dy[checkDir] + dy[moveDir],
                center.x + dx[checkDir] + dx[moveDir]
            };

            if (!check.canGo())
                return (false);

            ++checkDir;
        }

        t_pos newCenter = {center.y + dy[moveDir], center.x + dx[moveDir]};
        if (!newCenter.canGo())
            return (false);

        center = newCenter;
        return (true);
    }

    inline bool turn(void)
    {
        t_pos check = {center.y - 1, center.x - 1};

        while (check.y <= center.y + 1)
        {
            check.x = center.x - 1;
            while (check.x <= center.x + 1)
            {
                if (!check.canGo())
                    return (false);

                ++check.x;
            }
            ++check.y;
        }

        dir = (dir + 2) % dirSize;
        return (true);
    }

    inline bool operator==(const t_log &other) const
    {
        return (dir == other.dir && center == other.center);
    }
};

inline bool &getVisited(const t_log &log)
{
    return (visited[(log.dir == t_log::HORIZONTAL)][log.center.y][log.center.x]);
}

int bfs(t_log start, t_log end)
{
    int moveCnt = 1;
    std::queue<t_log> q;

    getVisited(start) = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_log cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_log next = cur;

                if (!next.move(dir))
                    continue ;

                bool &nextVisited = getVisited(next);
                if (nextVisited)
                    continue ;

                if (next == end)
                    return (moveCnt);

                nextVisited = true;
                q.push(next);
            }

            {
                t_log next = cur;

                if (next.turn())
                {
                    bool &nextVisited = getVisited(next);
                    if (!nextVisited)
                    {
                        if (next == end)
                            return (moveCnt);

                        nextVisited = true;
                        q.push(next);
                    }
                }
            }
        }
        ++moveCnt;
    }
    return (0);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos begin[t_log::SIZE];
    t_pos end[t_log::SIZE];
    int bIdx = 0, eIdx = 0;

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];
        for (int x = 0; x < size; ++x)
        {
            char &curSpace = map[y][x];

            switch (curSpace)
            {
            case BEGIN:
                begin[bIdx++] = {y, x};
                curSpace = EMPTY;
                break;
            case END:
                end[eIdx++] = {y, x};
                curSpace = EMPTY;
                break;
            }
        }
    }

    std::cout << bfs(begin, end) << '\n';
    return (0);
}
