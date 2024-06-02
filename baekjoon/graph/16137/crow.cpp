#include <iostream>
#include <queue>

enum e_space
{
    CLIFF = 0,
    LAND
};

struct t_pos
{
    int y, x;
    bool madeBridge, isBridge;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

const int MAX_SIZE = 10;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, mkBridgePeriod;
int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];

inline bool isBridge(const int &space)
{
    return (space > LAND);
}

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

inline bool canGo(const t_pos &pos)
{
    return (isBound(pos)
            && !(visited[pos.y][pos.x] & (1 << pos.madeBridge)));
}

inline bool canMakeBridge(const t_pos &cur, const t_pos &next)
{
    if (cur.madeBridge)
        return (false);

    int cliffCnt = 0;
    bool isCliff[] = {false, false, false, false};
    for (int dir = 0; dir < dirSize; ++dir)
    {
        const t_pos nn = {
            next.y + dy[dir],
            next.x + dx[dir],
            false,
            false
        };

        if (!isBound(nn))
            continue ;

        if (map[nn.y][nn.x] == CLIFF)
        {
            isCliff[dir] = true;
            ++cliffCnt;
        }
    }

    if (cliffCnt >= 3)
    {
        return (false);
    }

    if (cliffCnt <= 1)
    {
        return (true);
    }

    return ((isCliff[0] && isCliff[1])
            || (isCliff[2] && isCliff[3]));
}

inline bool canCrossBridge(int curTime, int bridge)
{
    return (curTime % bridge == 0);
}

int bfs(const t_pos start, const t_pos end)
{
    int curTime = 1;
    std::queue<t_pos> q;

    visited[start.y][start.x] = true;
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
                    cur.madeBridge,
                    cur.isBridge
                };

                if (!canGo(next))
                    continue ;

                int &nextSpace = map[next.y][next.x];
                next.isBridge = isBridge(nextSpace);
                if (next.isBridge)
                {
                    if (cur.isBridge)
                        continue ;

                    if (!canCrossBridge(curTime, nextSpace))
                    {
                        q.push(cur);
                        continue;
                    }
                }
                else if (nextSpace == CLIFF)
                {
                    if (!canMakeBridge(cur, next))
                    {
                        visited[next.y][next.x] |= (1 << next.madeBridge);
                        continue ;
                    }
                    else if (!canCrossBridge(curTime, mkBridgePeriod))
                    {
                        q.push(cur);
                        continue ;
                    }

                    next.isBridge = true;
                    next.madeBridge = true;
                }

                if (next == end)
                    return (curTime);

                visited[next.y][next.x] |= (1 << next.madeBridge);
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

    std::cin >> size >> mkBridgePeriod;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    std::cout << bfs({0, 0, false, false},
                        {size - 1, size - 1, false, false}) << '\n';
    return (0);
}
