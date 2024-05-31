#include <iostream>
#include <cstring>
#include <queue>

enum e_space
{
    EMPTY = 0,
    HOUSE,
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size, clientMoney;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

inline int maintenanceCost(int range)
{
    return (range * range
            + (range - 1) * (range - 1));
}

inline int isAffordable(int protectRange, int protectCnt)
{
    return (maintenanceCost(protectRange)
                <= protectCnt * clientMoney);
}

inline bool canGo(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size)
            && !visited[pos.y][pos.x]);
}

int getAffordableHouse(const t_pos &start)
{
    std::queue<t_pos> q;
    int protectRange = 1;
    int curProtect = (map[start.y][start.x] == HOUSE);
    int maxProtect = isAffordable(protectRange++, curProtect);

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
                const t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!canGo(next))
                    continue ;

                curProtect += (map[next.y][next.x] == HOUSE);
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        if (isAffordable(protectRange, curProtect))
        {
            maxProtect = curProtect;
        }
        ++protectRange;
    }
    return (maxProtect);
}

int    findMaxAffordableHouse(void)
{
    int maxHouse = 0;
    t_pos cur = {0, 0};

    for (; cur.y < size; ++cur.y)
    {
        for (cur.x = 0; cur.x < size; ++cur.x)
        {
            memset(visited, false, sizeof(visited));
            maxHouse = std::max(
                maxHouse,
                getAffordableHouse(cur)
            );
        }
    }
    return (maxHouse);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> size >> clientMoney;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                std::cin >> map[y][x];
            }
        }

        std::cout << "#" << t << ' ' << findMaxAffordableHouse() << '\n';
    }
    return (0);
}
